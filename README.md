![Image of bitFlowers Logo](https://download.crypto-city.com/aw/github.gif)

# Element (HYP)

Copyright (c) 2021 Element (HYP) Developers<br/>
Copyright (c) 2013-2021 HyperStake (HYP) Developers<br/>
Copyright (c) 2013 NovaCoin Developers<br/>
Copyright (c) 2011-2012 Bitcoin Developers<br/>

Distributed under the MIT/X11 software license, see the accompanying
file license.txt or http://www.opensource.org/licenses/mit-license.php.
This product includes software developed by the OpenSSL Project for use in
the OpenSSL Toolkit (http://www.openssl.org/).  This product includes
cryptographic software written by Eric Young (eay@cryptsoft.com).


Intro
-----
Element (HYP) is a Crypto-city rendition of HyperStake (HYP). It is 
is a free open source project derived from NovaCoin, with
the goal of providing a longterm energy-efficient Proof of Stake (PoS) based cryptocurrency.
Built on the foundation of Bitcoin and NovaCoin, innovations such as proof-of-stake
help further advance the field of crypto-currency.

Upgrade
-------
Upgrading from HyperStake (HYP) to Element (HYP):<br>

https://element-hyp.com/cc/how_to_update.pdf

Build Instructions (Linux)
-------
**If definitely Ubuntu 18.04 LTS (non GUI):**<br><br>
`sudo add-apt-repository ppa:bitcoin/bitcoin`
`sudo apt-get update`
`sudo apt-get install build-essential libtool autotools-dev autoconf pkg-config libssl-dev libboost-all-dev libdb4.8-dev libdb4.8++-dev libminiupnpc-dev automake`

### Else:

**Dependencies required for Element (HYP) with or without GUI:**<br><br>
`sudo apt-get install build-essential libtool autotools-dev autoconf pkg-config libssl-dev libboost-all-dev libdb5.3-dev libdb5.3++-dev libminiupnpc-dev automake`<br><br>
**Prepare build:**<br><br>
`./autogen.sh`

**Configure without GUI:**<br><br>
`./configure --with-incompatible-bdb --with-gui=no`

**Configure with GUI:**<br><br>
`sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler libqrencode-dev`

`./configure --with-incompatible-bdb --with-gui=qt5`

**Compile**<br><br>
`make`

Build Instructions (MacOS)
-------
### MacOS-64bit:
`Build a new blank Linux 18.04 (Bionic Beaver) Virtual Machine` <br>
`Allow "Software Updater" to cycle through and update`<br><br>
**Inside the terminal (change username according to yours):** <br><br>
`cd /home/username/` <br>
`sudo apt install git` <br>
`git clone https://github.com/crypto-city/Element-HYP` <br>
`cd Element-HYP/script` <br>
`./macOS.sh` <br><br>
**Once completed:** <br><br>
`cd /home/username/release/Element-HYP-macOS`

Build Instructions (Windows)
-------
### Windows-32bit:
`Build a new blank Linux 18.04 (Bionic Beaver) Virtual Machine` <br>
`Allow "Software Updater" to cycle through and update`<br><br>
**Inside the terminal (change username according to yours):** <br><br>
`cd /home/username/` <br>
`sudo apt install git` <br>
`git clone https://github.com/crypto-city/Element-HYP` <br>
`cd Element-HYP/script` <br>
`./w32.sh` <br><br>
**Once completed:** <br><br>
`sudo su root` <br>
`cd /root/release/Element-HYP-w32/home/username/Element-HYP/depends/i686-w64-mingw32/bin/` <br>
`cp -r element-qt.exe /home/username/` <br>
`cd /home/username/` <br>
`chmod 777 element-qt.exe` <br>
### Win-64bit:
`Build a new blank Linux Ubuntu 20.04.3 LTS (Focal Fossa) Virtual Machine` <br>
`Allow "Software Updater" to cycle through and update`<br><br>
**Inside the terminal (change username according to yours):** <br><br>
`cd /home/username/`<br>
`wget https://download.crypto-city.com/aw/w64.sh`<br>
`sudo chmod ugo+x w64.sh`<br>
`sudo su root`<br>
`./w64.sh`<br>
`1 + ENTER`<br><br>
**Once completed:** <br><br>
`cd /home/username/Element-HYP/src/qt`<br>
`cp -r element-qt.exe /home/username/`<br>
`cd /home/username`<br>
`chmod 777 element-qt.exe`<br>


