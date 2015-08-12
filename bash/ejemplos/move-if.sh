#! /bin/bash
#
# Aplica mv los archivos del presente directorio si tienen un tamaño menor al
# especificado en el parámetro provisto por el usuario.

tamano="$1"
filePath="$2"

if [[ "$filePath" != */ ]] ; then  

    dirName="$filePath"
    filePath="$filePath""/"

else

    dirName="${filePath%?}"

fi



if [[ -d "$dirName" ]] ; then

    for file in *.* ; do

        SizeName=`ls "$file" -s`
        Size=`awk ' { print $1 } '  <<< $SizeName`
        

        if  [[ "$Size" = *[[:digit:]]* ]] ; then
            if [ "$Size" -lt "$tamano" ] ; then
                if ! [[ -d "$file" ]] ; then
                    printf "Moviendo %s a %s\n" "$file" "$filePath"
                    mv "$file" "$filePath"
                else 
                    echo "Error: " $file " es un directorio"
                fi
            fi
        fi
    done

else 
    >&2 echo "Error: no existe el directorio " $dirName
fi


