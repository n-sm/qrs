#! /bin/bas

OUT=$1.pdf

if [ "$1" != "$OUT" ] ; then 

    echo "Output file :" $OUT
    gs -sDEVICE=pdfwrite -dCompatibilityLevel=1.4 -dPDFSETTINGS=/screen -dNOPAUSE -dQUIET -dBATCH -sOutputFile=$OUT $1

else

    >&2 echo "error"

fi


