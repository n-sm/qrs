#! /bin/bash

for file in "$( find . -name \*.pdf )" ; do

printf "%s\n" "${file//.pdf/.txt}"

done
