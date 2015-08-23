#!/bin/bash

declare FILE=$1

cat "$FILE" |  tr ',' ' ' | sed "s/.$//g" | awk -f scripts/flush-alphanumeric.awk  
#cat "$FILE" | tr ',' ' ' | sed "s/.$//g" 
