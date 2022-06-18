

[![Image of Element Logo](https://download.crypto-city.com/aw/github.gif)](https://www.crypto-city.com/element-hyp/info/)

# Element (HYP)

Introduction 
-----
Element (HYP) is a [Crypto-city](https://www.crypto-city.com/) rendition of HyperStake (HYP). It is an advanced Proof of Stake (PoS) cryptocurrency. Element (HYP) honours the original protocol; not a hard fork or swap. The project is open source and is derived from Bitcoin, NovaCoin, and forked directly from TruckCoin (TRK). 
<br><br>
Embarking on a new journey, Element (HYP) aims to empower the human experience; the power of you. The [Crypto-city](https://www.crypto-city.com/) team has provided the necessary performance and UI upgrades that simplifies the user experience. 
<br><br>
To learn more, please visit: 
[Crypto-city](https://www.crypto-city.com/element-hyp/info/)

Specifications
----- 
Block time: 90 seconds<br>
Block size: 1MB<br>
Algorithm: X11<br>
Minimum stake maturity: 8.8 days<br>
Maximum stake maturity: 30 days<br>
Maximum Stake reward: 1,000 HYP<br>
Maximum stake rewards per day: 960,000 HYP<br>

Upgrade
-------
Upgrading from HyperStake (HYP) to Element (HYP):<br>

https://download.crypto-city.com/hyp/docs/how_to_update.pdf

Video Guide
-------
This video walkthrough is a full breakdown of how to properly make full use of the Element (HYP) cryptocurrency desktop wallet application. From installation right through to how you can properly backup and secure your Element (HYP) coins; empowering you to take full control of your HYP assets and confidently participating within the rapidly evolving Element (HYP) crypto ecosystem.<br>

**Please click the image blow to access the video:**

[![Element HYP video guide](https://element-hyp.com/guide_thumbnail.png)](https://youtu.be/hyVt8kBHs_o)

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

-----
[![Image of Crypto-city Logo](https://download.crypto-city.com/aw/cc.png)](https://www.crypto-city.com/)
-----
Copyright (c) 2021 Element (HYP) Developers<br/>
Copyright (c) 2013-2021 HyperStake (HYP) Developers<br/>
Copyright (c) 2013 NovaCoin Developers<br/>
Copyright (c) 2011-2012 Bitcoin Developers<br/>

Distributed under the MIT/X11 software license, see the accompanying
file license.txt or http://www.opensource.org/licenses/mit-license.php.
This product includes software developed by the OpenSSL Project for use in
the OpenSSL Toolkit (http://www.openssl.org/).  This product includes
cryptographic software written by Eric Young (eay@cryptsoft.com).
