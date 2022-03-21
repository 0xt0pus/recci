#!/bin/bash

#!/bin/bash
figlet -f maxiwi "RECCI" 

echo "     _.-._   "
echo "   .' | |  ."
echo "  /   | |   \ "
echo " |    | |    | "
echo " |____|_|____| "
echo " |____(_)____| "
echo " /|(o)| |(o)|\ "
echo "/ |   | |   | \\\\"
echo "\ |  (|_|)  | /"
echo " | \/     \/ |"
echo " / /  ___  \ \  VK"
echo "(             )"
echo " \           /"
echo "   ._______.'"


echo "welcome to script"

echo "Enter the ip address"

read ip





echo "Which tool you want to use ?"
echo "[0] ping"
echo "[1] nmap check all ports"
echo "[2] Common Ports"
echo "[3] Directory enamuration"
echo "[4] robots.txt"
echo "[5] sitemap.xml"
echo "[6] Find the subdomains"
echo "[7] Find all the possible vulnerabilities"
echo "[8] Find all the email addresses"
echo "[9] Generate full report from all the finding"
echo "[10] whatweb"
echo "[11] whois"
echo "[12] exit"

read tool




while [[ $tool -ne 12 ]]
do





case $tool in

	0)
		echo "Please wait..."
		ping $ip -c 10 > ping/file # pinging the site and storing the data in file (text file)
		g++ ping/temp.cpp -o ping/run # the cpp file name and compiling the file
		cd ping
		./run
		cd ..

		;;

	1)
		echo "Running nmap for all the ports. it will take some times"
		echo "Please Wait..."
		nmap -sC -sV -p- --min-rate 2500 $ip > nmap/nmapRead
		wait
		g++ nmap/nmapTextManipulation.cpp -o run
		./run
		echo "Execution is Done "
		echo "The following are Open Ports"
		cat nmap/OpenPorts
		;;
	
	2)
    	echo "Running nmap for common ports. it will take some times"
		echo "Please Wait..."
		nmap -sC -sV --min-rate 2500 $ip > nmap/nmapRead
		wait
		g++ nmap/nmapTextManipulation.cpp -o run
		./run
		echo "Execution is Done "
		echo "The following are Open Ports"
		cat nmap/OpenPorts
    	;;

	3)
    	echo "Now running the GoBuster"
		gobuster dir -u $ip -w gobuster/wordlist.txt > gobuster/gobusterInput
		cat gobuster/gobusterInput
    	;;

	
	4)
    	code=$(curl -s -o /dev/null -w "%{http_code}" $ip/robots.txt)
    	if [[ $code -eq 404 ]];
    	then
    		echo "Robots.txt does not exist in this site"
    	else
    		echo "the following is the result of robots.txt"
    		echo 
    		curl $ip/robots.txt > robots.txt
    		cat robots.txt
    	fi

    	;;
	5)
    	code=$(curl -s -o /dev/null -w "%{http_code}" $ip/sitemap.xml)
    	if [[ $code -eq 404 ]];
    	then
    		echo "sitemap.xml does not exist in this site"
    	else
    		echo 
    		curl $ip/sitemap.xml > sitemap.xml 
    		echo "The result of sitemap.xml has been written into file"
    	fi
    	;;

	6)
    	echo "Finding all the subdomains."
    	echo "Please wait..."
    	sublist3r -d $ip -n > subdomains/resultoOfSublist3r.txt
    	wait
    	cd subdomains

    	g++ sub.cpp 
    	./a.out
    	cd ..
    	echo "All the subdomains are being written into file resultoOfSublist3r"
    	rm subdomains/resultoOfSublist3r.txt
    	;;

	7)
    	# for finding the possible vulnerabilities
    	echo "Please wait..."
    	rm vulnerabilities/vuln
		while read -r variableName; do
		searchsploit -w --colour $variableName >> vulnerabilities/vuln
		done < nmap/Versions
		echo "All the possible exploits are been identified and stored"
    	;;

    8)

		echo "Now finding the emails."
		echo "Please wait"
		theHarvester -d $ip -b google > findemails/file3.txt
		g++ findemails/harvest.cpp -o findemails/run # the cpp file name and compiling the file
		findemails/./run # running the cpp program

		;;



    9)
		echo "The Ip and Ping details here " > all
		echo "--------------------------------------" >> all
		cat ping/file >> all
		echo >> all
		echo >> all 

		echo "The open ports are " >> all
		echo "--------------------------------------" >> all
		cat nmap/OpenPorts >> all
		echo >> all
		echo >> all

		echo "The Services and Versions are " >> all
		echo "--------------------------------------" >> all
		cat nmap/ServicesAndVersions >> all
		echo >> all
		echo >> all


		echo "The found directories are " >> all
		echo "--------------------------------------" >> all
		cat gobuster/gobusterInput >> all
		echo >> all
		echo >> all



		echo "The emails are " >> all
		echo "--------------------------------------" >> all
		cat findemails/file3.txt >> all
		echo >> all
		echo >> all

		echo "The web technologies used are  are " >> all
		echo "--------------------------------------" >> all
		cat whatweb/file.txt >> all
		echo >> all
		echo >> all

		echo "The result of robots.txt " >> all
		echo "--------------------------------------" >> all
		cat robots.txt >> all
		echo >> all
		echo >> all

		echo "The result of sitemap.xml " >> all
		echo "--------------------------------------" >> all
		cat sitemap.xml >> all
		echo >> all
		echo >> all		

		echo "The subdomains are " >> all
		echo "--------------------------------------" >> all
		cat subdomains/finalresultoOfSublist3r.txt >> all
		echo >> all
		echo >> all


		echo "The whois Data is  " >> all
		echo "--------------------------------------" >> all
		cat whois/WhoisData >> all
		echo >> all
		echo >> all



		echo "The possible vulnerabilities are " >> all
		echo "--------------------------------------" >> all
		cat vulnerabilities/vuln >> all
		echo >> all
		echo >> all

		enscript -p all.ps all
		ps2pdf all.ps final.pdf
		rm all.ps
		rm all

    	;;





    10)

		# echo "destination ${{ip}}"

		echo "Now finding the web info."
		echo "Please wait"
		whatweb -v --color='never' $ip > whatweb/file2.txt #running the whatweb
		gawk '{gsub(/[[:cntrl:]]/,x)}1' whatweb/file2.txt > whatweb/file.txt # removing the binary characters
		rm whatweb/file2.txt
		g++ whatweb/whatwebprog.cpp -o whatweb/run # the cpp file name and compiling the file
		cd whatweb
		./run # running the cpp program
		cd ..
		;;


	11)

		echo "Now running whois"
		whois $ip > whois/data
		cd whois
		g++ text.cpp
		./a.out
		rm data
		cd ..




		;;



	*)
    	echo "Please choose valid option"
    	;;

esac

echo "Which tool you want to use ?"
echo "[0] ping"
echo "[1] nmap check all ports"
echo "[2] Common Ports"
echo "[3] Directory enamuration"
echo "[4] robots.txt"
echo "[5] sitemap.xml"
echo "[6] Find the subdomains"
echo "[7] Find all the possible vulnerabilities"
echo "[8] Find all the email addresses"
echo "[9] Generate full report from all the finding"
echo "[10] whatweb"
echo "[11] whois"
echo "[12] exit"

read tool


done




# echo "Now running the GoBuster"

# gobuster dir -u 192.168.37.134 -w gobuster/wordlist.txt > gobuster/gobusterInput
