#!/bin/bash
sudo apt-get update
sudo apt install figlet toilet 
sudo apt-get install ghostscript
sudo apt-get install enscript 
sudo apt-get install sublist3r
sudo apt-get install gobuster
cd /usr/share
git clone https://github.com/xero/figlet-fonts
mv figlet-fonts/* figlet && rm -rf figlet-fonts
