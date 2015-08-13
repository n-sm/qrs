#! /bin/bash

echo hola

for (( i = 1 ; i <= $# ; ++i )) ; do

    eval pari=\$$i
    pari2=$pari
    printf "$%s: %s\n" $i $pari

done


sed '/^a test$/{$!{N;s/linea\ntercera/REEMPL/;ty;P;D;:y}}' text.txt
