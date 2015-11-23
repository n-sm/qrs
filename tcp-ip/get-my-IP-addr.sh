#!/bin/bash
# http://unix.stackexchange.com/questions/22615/how-can-i-get-my-external-ip-address-in-bash
dig +short myip.opendns.com @resolver1.opendns.com
# curl -s http://whatismijnip.nl |cut -d " " -f 5
