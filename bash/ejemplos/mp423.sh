#!/bin/bash
# Extraer la musica de un video.
	    
while getopts ":d" opt;
do
    case $opt in
	d)
	    BORRAR=true
	    ;;
	\?)
	    echo "Invalid option: -$OPTARG" >&2
	    exit
	    ;;
    esac
done

shift "$((OPTIND - 1))"

declare DESDE="$@"
declare HASTA=${DESDE%.*}".mp3"

if [ -f "$HASTA" ] ;
then
    echo El mp3 ya existe
else
    printf "extrayendo:\n%s\n\nde:\n%s\n\n" "$HASTA"  "$DESDE"
    ffmpeg -i "$DESDE" -vn -ar 44100 -ac 2 -ab 192 -f mp3 "$HASTA" && echo ok ;\
    if	[ $BORRAR ] ;
    then
	echo Borramos "$DESDE"
	rm "$DESDE"
    else
	echo No borramos $DESDE
    fi
fi
