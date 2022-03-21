#!/bin/bash
sudo apt install figlet toilet 
sudo apt-get install ghostscript
sudo apt-get install enscript 
sudo apt-get install sublist3r
cd /usr/share
git clone https://github.com/xero/figlet-fonts
mv figlet-fonts/* figlet && rm -rf figlet-fonts