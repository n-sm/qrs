#!/bin/bash

declare FILE=$1

while IFS= read -r LINE; do 
  echo "$LINE"
done < $FILE
