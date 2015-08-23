#!/bin/bash
# Este script es para reemplazar los espacios en blanco 
# de los nombres de los archivos pdf por guiones bajos
for file in *.pdf; do
    file_p=${file// /_}
    if  [ "$file" != "$file_p" ]; then
	mv -b "$file" "$file_p"
    fi
done
exit 0
