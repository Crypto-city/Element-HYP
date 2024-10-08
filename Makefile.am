ACLOCAL_AMFLAGS = -I build-aux/m4
SUBDIRS = src
.PHONY: deploy FORCE

GZIP_ENV="-9n"

BITCOIND_BIN=$(top_builddir)/src/elementd$(EXEEXT)
BITCOIN_QT_BIN=$(top_builddir)/src/qt/element-qt$(EXEEXT)
BITCOIN_WIN_INSTALLER=$(PACKAGE)-$(PACKAGE_VERSION)-win$(WINDOWS_BITS)-setup$(EXEEXT)

OSX_APP=Element-Qt.app
OSX_DMG=Element-Qt.dmg
OSX_DEPLOY_SCRIPT=$(top_srcdir)/contrib/macdeploy/macdeployqtplus
OSX_FANCY_PLIST=$(top_srcdir)/contrib/macdeploy/fancy.plist
OSX_INSTALLER_ICONS=$(top_srcdir)/src/qt/res/icons/bitcoin.icns
OSX_PLIST=$(top_srcdir)/share/qt/Info.plist #not installed
OSX_QT_TRANSLATIONS = da,de,es,hu,ru,uk,zh_CN,zh_TW

THEMES=$(top_srcdir)/src/qt/res/themes

DIST_DOCS = $(wildcard doc/*.md) $(wildcard doc/release-notes/*.md)

WINDOWS_PACKAGING = $(top_srcdir)/share/pixmaps/bitcoin.ico \
  $(top_srcdir)/share/pixmaps/nsis-header.bmp \
  $(top_srcdir)/share/pixmaps/nsis-wizard.bmp \
  $(top_srcdir)/doc/README_windows.txt

OSX_PACKAGING = $(OSX_DEPLOY_SCRIPT) $(OSX_FANCY_PLIST) $(OSX_INSTALLER_ICONS) \
  $(top_srcdir)/contrib/macdeploy/background.png \
  $(top_srcdir)/contrib/macdeploy/DS_Store \
  $(top_srcdir)/contrib/macdeploy/detached-sig-apply.sh \
  $(top_srcdir)/contrib/macdeploy/detached-sig-create.sh

COVERAGE_INFO = baseline_filtered_combined.info baseline.info block_test.info \
  test_bitcoin_filtered.info total_coverage.info \
  baseline_filtered.info block_test_filtered.info \
  test_bitcoin_coverage.info test_bitcoin.info

dist-hook:
	-$(MAKE) -C $(top_distdir)/src/secp256k1 distclean
	-$(GIT) archive --format=tar HEAD -- src/clientversion.cpp | $(AMTAR) -C $(top_distdir) -xf -

distcleancheck:
	@:

$(BITCOIN_WIN_INSTALLER): all-recursive
	$(MKDIR_P) $(top_builddir)/release
	STRIPPROG="$(STRIP)" $(INSTALL_STRIP_PROGRAM) $(BITCOIND_BIN) $(top_builddir)/release
	STRIPPROG="$(STRIP)" $(INSTALL_STRIP_PROGRAM) $(BITCOIN_QT_BIN) $(top_builddir)/release
	@test -f $(MAKENSIS) && $(MAKENSIS) $(top_builddir)/share/setup.nsi || \
	  echo error: could not build $@

$(if $(findstring src/,$(MAKECMDGOALS)),$(MAKECMDGOALS), none): FORCE
	$(MAKE) -C src $(patsubst src/%,%,$@)

$(OSX_APP)/Contents/PkgInfo:
	$(MKDIR_P) $(@D)
	@echo "APPL????" > $@

$(OSX_APP)/Contents/Resources/empty.lproj:
	$(MKDIR_P) $(@D)
	@touch $@

$(OSX_APP)/Contents/Info.plist: $(OSX_PLIST)
	$(MKDIR_P) $(@D)
	$(INSTALL_DATA) $< $@

$(OSX_APP)/Contents/Resources/bitcoin.icns: $(OSX_INSTALLER_ICONS)
	$(MKDIR_P) $(@D)
	$(INSTALL_DATA) $< $@

$(OSX_APP)/Contents/MacOS/Element-Qt: $(BITCOIN_QT_BIN)
	$(MKDIR_P) $(@D)
	STRIPPROG="$(STRIP)" $(INSTALL_STRIP_PROGRAM)  $< $@

OSX_APP_BUILT=$(OSX_APP)/Contents/PkgInfo $(OSX_APP)/Contents/Resources/empty.lproj \
  $(OSX_APP)/Contents/Resources/bitcoin.icns $(OSX_APP)/Contents/Info.plist \
  $(OSX_APP)/Contents/MacOS/Element-Qt

if BUILD_DARWIN
$(OSX_DMG): $(OSX_APP_BUILT) $(OSX_PACKAGING)
	$(OSX_DEPLOY_SCRIPT) $(OSX_APP) -add-qt-tr $(OSX_QT_TRANSLATIONS) -translations-dir=$(QT_TRANSLATION_DIR) -dmg -fancy $(OSX_FANCY_PLIST) -verbose 2

deploydir: $(OSX_DMG)
else
APP_DIST_DIR=$(top_builddir)/dist
APP_DIST_EXTRAS=$(APP_DIST_DIR)/.background/background.png $(APP_DIST_DIR)/.DS_Store $(APP_DIST_DIR)/Applications

$(APP_DIST_DIR)/Applications:
	@rm -f $@
	@cd $(@D); $(LN_S) /Applications $(@F)

$(APP_DIST_EXTRAS): $(APP_DIST_DIR)/$(OSX_APP)/Contents/MacOS/Element-Qt

$(OSX_DMG): $(APP_DIST_EXTRAS)
	$(GENISOIMAGE) -no-cache-inodes -D -l -probe -V "Element-Qt" -no-pad -r -apple -o $@ dist

$(APP_DIST_DIR)/.background/background.png:
	$(MKDIR_P) $(@D)
	$(INSTALL) $(top_srcdir)/contrib/macdeploy/background.png $@
$(APP_DIST_DIR)/.DS_Store:
	$(INSTALL) $(top_srcdir)/contrib/macdeploy/DS_Store $@

$(APP_DIST_DIR)/$(OSX_APP)/Contents/MacOS/Element-Qt: $(OSX_APP_BUILT) $(OSX_PACKAGING)
	INSTALLNAMETOOL=$(INSTALLNAMETOOL)  OTOOL=$(OTOOL) STRIP=$(STRIP) $(OSX_DEPLOY_SCRIPT) $(OSX_APP) -translations-dir=$(QT_TRANSLATION_DIR) -add-qt-tr $(OSX_QT_TRANSLATIONS) -verbose 2

deploydir: $(APP_DIST_EXTRAS)
endif

if TARGET_DARWIN
appbundle: $(OSX_APP_BUILT)
deploy: $(OSX_DMG)
endif
if TARGET_WINDOWS
deploy: $(BITCOIN_WIN_INSTALLER)
endif

$(BITCOIN_QT_BIN): FORCE
	$(MAKE) -C src qt/$(@F)

$(BITCOIND_BIN): FORCE
	$(MAKE) -C src $(@F)

if USE_LCOV

baseline.info:
	$(LCOV) -c -i -d $(abs_builddir)/src -o $@

baseline_filtered.info: baseline.info
	$(LCOV) -r $< "/usr/include/*" -o $@

baseline_filtered_combined.info: baseline_filtered.info
	$(LCOV) -a baseline_filtered.info -o $@

test_bitcoin.info: baseline_filtered_combined.info
	$(MAKE) -C src/ check
	$(LCOV) -c -d $(abs_builddir)/src -t test_bitcoin -o $@
	$(LCOV) -z -d $(abs_builddir)/src

test_bitcoin_filtered.info: test_bitcoin.info
	$(LCOV) -r $< "/usr/include/*" -o $@

block_test.info: test_bitcoin_filtered.info
	$(MKDIR_P) qa/tmp
	-@TIMEOUT=15 qa/pull-tester/run-bitcoind-for-test.sh $(JAVA) -jar $(JAVA_COMPARISON_TOOL) qa/tmp/compTool 0
	$(LCOV) -c -d $(abs_builddir)/src --t BitcoinJBlockTest -o $@
	$(LCOV) -z -d $(abs_builddir)/src

block_test_filtered.info: block_test.info
	$(LCOV) -r $< "/usr/include/*" -o $@

test_bitcoin_coverage.info: baseline_filtered_combined.info test_bitcoin_filtered.info
	$(LCOV) -a baseline_filtered.info -a test_bitcoin_filtered.info -o $@

total_coverage.info:  baseline_filtered_combined.info test_bitcoin_filtered.info block_test_filtered.info
	$(LCOV) -a baseline_filtered.info -a test_bitcoin_filtered.info -a block_test_filtered.info -o $@ | $(GREP) "\%" | $(AWK) '{ print substr($$3,2,50) "/" $$5 }' > coverage_percent.txt

test_bitcoin.coverage/.dirstamp:  test_bitcoin_coverage.info
	$(GENHTML) -s $< -o $(@D)
	@touch $@

total.coverage/.dirstamp: total_coverage.info
	$(GENHTML) -s $< -o $(@D)
	@touch $@

cov: test_bitcoin.coverage/.dirstamp total.coverage/.dirstamp

endif

EXTRA_DIST = $(top_srcdir)/share/genbuild.sh $(DIST_DOCS) $(WINDOWS_PACKAGING) $(OSX_PACKAGING)

CLEANFILES = $(OSX_DMG) $(BITCOIN_WIN_INSTALLER)

.INTERMEDIATE: $(COVERAGE_INFO)

clean-local:
	rm -rf test_bitcoin.coverage/ total.coverage/ $(OSX_APP)
