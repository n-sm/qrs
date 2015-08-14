#!/bin/bash

# Sacar del nombre de cada archivo del presente directorio
# la string dada como argumento (si corresponde).

declare STR=$1

for file in *$STR*; do
    file_p=${file//$STR}
    echo moviendo de $file a $file_p
    mv -b "$file" "$file_p"
done

