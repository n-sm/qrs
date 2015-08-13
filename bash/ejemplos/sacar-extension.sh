#!/bin/bash
# sacar la extension a todos los archivos segun se indique en argumento.

for file in *.$1; do
    file_p=${file//.$1}
    mv -b "$file" "$file_p"
done
exit 0
