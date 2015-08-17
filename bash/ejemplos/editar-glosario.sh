#!/bin/bash
#
# Este ejemplo muestra como editar todos los archivos de un
# directorio con extension `.en` agregando la string " es:"
# al inicio de la segunda linea de cada uno.

for f in *.en
do
    sed -i "2s/^/ es:/" "$f"
done

# en la terminal:
# for f in *.en ; do sed -i '2s/^/ es:/' "$f" ; done
