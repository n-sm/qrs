#!/bin/bash
# sacar la extension a todos los archivos segun se indique en argumento.

for file in *listA*; do
    file_p=${file/listA/qrg}
    mv -b "$file" "$file_p"
done
exit 0
