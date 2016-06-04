#!/bin/bash

nip=192.168.0
for ip in {100..105}
do
    ping -c 1 $nip.$ip >/dev/null
   [ $? -eq 0 ] && echo "192.168.0.$ip UP" || :
done
