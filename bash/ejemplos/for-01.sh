#!/bin/bash
# IFS='\n' es para que no tome los espacios en blanco de los nombres
# como separadores de lineas.

IFS=$'\n'
for f in `ls *3` 
do 
    echo "$f"
    mplayer "$f"
    echo "borramos " "$f" "? (s/n)"
    read input
    if (( $input == "s")) 
    then 
	echo "ok, borramos"
#	mv "$f" tmp
    fi
done
