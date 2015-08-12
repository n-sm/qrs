#! /bin/bash

hasta=$RANDOM
outFileName="random-out"
outFileExt=".txt"
outFile=$outFileName$outFileExt
fileCount=0

for (( count=0 ; count < 3 ; count++ ))

do

    n1=$RANDOM
    n2=$RANDOM

    dife=$(( n1 - n2 ))

done

    printf "%d\n" $dife >> "$outFile"


done
