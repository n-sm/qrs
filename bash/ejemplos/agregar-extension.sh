#!/bin/bash
# agregar la extension a todos los archivos que no la tengan
# segun se indique en argumento.

for file in `find . -maxdepth 1 -type f`; do

    file_p=${file//.\/}
    if [[ $file_p != *'.'* ]]
    then
        mv $file_p $file_p.$1;
    fi
done
