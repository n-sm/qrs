# Esta función devuelve una lista con todos los directorios y subdirectorios del
# directorio actual y su tamaño.
# Para obtener el resultado ordenado por tamaño, escribir:
# $ dirs-size | sort -n


function dirs-size {

if [ "$( find -type d )" == "." ] ; then

>&2 echo ${FUNCNAME[0]} ": El directorio actual no tiene subdirectorios."

else

    for dir in " */" ; do

LINE=$( du -d 0 $dir )

        printf "%s \n" "$LINE"

    done

fi

}


