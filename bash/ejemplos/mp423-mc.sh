#!/bin/bash
# Extraer la musica de un video.
## PARA PODER DE USAR hay que instalar libav-tools:
# sudo apt-get isntall libav-tools

declare DESDE=$1
declare HASTA=${DESDE%.*}".mp3"
declare INPUT

if [ -f "$HASTA" ] ;
then
    echo El mp3 ya existe
else
    printf "extrayendo:\n%s\n\nde:\n%s\n\n" "$HASTA"  "$DESDE"
    ffmpeg -i "$DESDE" -vn -ar 44100 -ac 2 -ab 192 -f mp3 "$HASTA" && echo ok ;\
    printf "Borramos %s?\n(S/n)\n" "$DESDE"
    read INPUT
    if	[[ "$INPUT" == "S" ]] ;
    then
	echo Borramos "$DESDE"
	rm "$DESDE"
    else
	echo No borramos $DESDE
    fi
    
fi
