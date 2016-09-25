#!/bin/bash
#http://askubuntu.com/questions/82480/how-to-see-all-computers-connected-to-a-network 

#declare NRO=$1

for ip in $(seq 100 105)
do 
	printf "viendo 192.168.0.%s " $ip
	ping -c 1 192.168.0.$ip>/dev/null;
    [ $? -eq 0 ] && printf "\n\n192.168.1.%s UP\n\n " $ip  || : ;
done
