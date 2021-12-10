[![Image of Element Logo](https://download.crypto-city.com/aw/github.gif)](https://www.crypto-city.com/element-hyp/info/)

# Element (HY) Discord Price Tracker Bot
This bot will sit in the member list of the Discord server and display USD/BTC price of Element (HYP) and it's % movement over 24 hours. 

Dependencies
-----

`Build a new blank Linux 18.04 (Bionic Beaver) Virtual Machine` <br>
`Allow "Software Updater" to cycle through and update`<br>
`sudo apt-get update && sudo apt-get upgrade && sudo apt install git`<br>
`sudo apt install software-properties-common -y`<br>
`sudo add-apt-repository ppa:deadsnakes/ppa`<br>
`sudo apt install python3.7 -y`<br>

Add Python 3.7 to the available alternatives
-----
`sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.7 1`<br>

Set python3.7 as the default python
-----
`sudo update-alternatives --set python /usr/bin/python3.7`<br>

Install pip
-----
`sudo apt install python3-pip -y`<br>
`sudo python -m pip install --upgrade pip`<br>

Downloading repo
-----
`cd /home/username/`<br>
`git clone https://github.com/anthonyrjwood/element_hyp_discord_price_bot.git`<br>

Additional Dependencies
-----
`pip install -r requirements.txt`<br>

Cache the CoinGecko cryptocurrency ticker list
-----
`cd /home/username/Desktop/lab/element_hyp_discord_price_bot`<br>
`python crypto_cache.py -v`<br>

Configure crypto_config.yaml
-----
`nano crypto_config.yaml`

HYP:<br>
    priceUnit:<br>
        - USD<br>
        - BTC<br>
    decimalPlace:<br>
        - 8<br>
        - 8<br>
    updateFreq: 60<br>
    discordBotKey: <Discord bot token><br>
    guildId: 385895423073714187<br>
<br>
`CTRL + X`<br>
`y`<br>
`ENTER`<br>

Run
-----
`python cfgi_run.py`

Deploy
-----
Once you are familiar with running a single sidebar bot, you can run multiple bots concurrently by calling `./bot.sh` and kill all bots by calling `./kill.sh`. You might want to modify the commands in `./bot.sh` to suit your own needs.

-----
[![Image of Crypto-city Logo](https://download.crypto-city.com/aw/cc.png)](https://www.crypto-city.com/)




