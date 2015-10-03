#!/bin/bash
# http://superuser.com/questions/261818/how-can-i-list-all-ips-in-the-connected-network-through-terminal-preferably
sudo arp-scan --interface=wlan0 --localnet

# en windows: ipconfig # linea 'Direccion IPv4'
