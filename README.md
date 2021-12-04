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
the goal of providing a long-term energy-efficient Proof of Stake (PoS) based crypto-currency.
Built on the foundation of Bitcoin and NovaCoin, innovations such as proof-of-stake
help further advance the field of crypto-currency.

Setup
-----
Unpack the files into a directory and run:<br/>
<br/>
 bin/32/elementd (headless, 32-bit)<br/>
 bin/64/elementd (headless, 64-bit)<br/>

The software automatically finds other nodes to connect to.  You can
enable Universal Plug and Play (UPnP) with your router/firewall
or forward port 

18775 (TCP) to your computer so you can receive
incoming connections.  element works without incoming connections,
but allowing incoming connections helps the element network.

Upgrade
-------
All your existing coins/transactions should be intact with the upgrade.
To upgrade first backup wallet
elementd backupwallet <destination_backup_file>
Then shutdown elementd by
elementd stop
Start up the new elementd.


See the element site:
  https://www.crypto-city.com/index.php/element-hyp/info
for help and more information.

Build Instructions (Linux)
-------
### (If definitely Ubuntu 18.04 LTS) (non GUI):
`sudo add-apt-repository ppa:bitcoin/bitcoin`
`sudo apt-get update`
`sudo apt-get install build-essential libtool autotools-dev autoconf pkg-config libssl-dev libboost-all-dev libdb4.8-dev libdb4.8++-dev libminiupnpc-dev automake`

### Else:

### Dependencies required for Element (HYP) with or without GUI:
`sudo apt-get install build-essential libtool autotools-dev autoconf pkg-config libssl-dev libboost-all-dev libdb5.3-dev libdb5.3++-dev libminiupnpc-dev automake`

`./autogen.sh`

### Configure without GUI:
`./configure --with-incompatible-bdb --with-gui=no`

### Configure with GUI:
`sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler libqrencode-dev`

`./configure --with-incompatible-bdb --with-gui=qt5`

### Compile
`make`

Build Instructions (Windows)
-------
### Windows-32bit:
`Build a new blank Linux 18.04 (Bionic Beaver) Virtual Machine` <br><br>
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

Build Instructions (MacOS)
-------
### MAcOS-64bit:
`Build a new blank Linux 18.04 (Bionic Beaver) Virtual Machine` <br><br>
**Inside the terminal (change username according to yours):** <br><br>
`cd /home/username/` <br>
`sudo apt install git` <br>
`git clone https://github.com/crypto-city/Element-HYP` <br>
`cd Element-HYP/script` <br>
`./macOS.sh` <br><br>
**Once completed:** <br><br>
`cd /home/icryptony/release/Element-HYP-macOS`
