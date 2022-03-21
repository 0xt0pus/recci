#!/bin/bash

echo "welcme to script"

echo "Running NMAP, Please wait..."


nmap -sC -sV --min-rate 2500 192.168.37.134 > nmapRead 

wait

echo "Done, Now compiling c++ file "

g++ nmapTextManipulation.cpp -o run

echo "Now executing the file "

./run

echo "Execution is Done "


