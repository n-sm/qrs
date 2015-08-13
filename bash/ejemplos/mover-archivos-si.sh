#!/bin/bash



for file in *.* ; do

    NM=$file
    SizeName=`ls "$NM" -s`
    Size=`awk ' { print $1 } '  <<< $SizeName`
    Name=`awk '{print substr($0, index($0,$2))}' <<< $SizeName`

 #   printf "file: %s\nSN: %s, S= %d, N:%s\n" "$file" "$SizeName" "$Size" "$Name"
    # prueba si es entero:

   if  [[ $Size = *[[:digit:]]* ]] ; then
        if [ $Size -gt $tamano ] ; then
            printf "Copiando %s\n" "$Name"
           cp "$Name" "./sets/$Name"
        fi
    fi
done
