#!/bin/bash
# 

for file in *.*; do

    file_p=${file//./}
#    cp -b "$file" "$file_p"
echo $file
#echo $file_p
done
exit 0

# 
# for file in *$1*; do
#     file_p=${file//$1}
#     mv -b "$file" "$file_p"
# done
