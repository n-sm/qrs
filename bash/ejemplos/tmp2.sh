#! /bin/bash

optA="defaultA"
optB="defaultB"
optC="defaultC"

while getopts :a:b:c SWITCH ; do

    case $SWITCH in

        a) echo opcion a
            optA=a
            ;;

        b) echo opcion b
            optB=b

            ;;

        c) echo opcion c
            optC=c
            ;;
    esac

done

echo optA es $optA
echo optB es $optB
echo optC es $optC
