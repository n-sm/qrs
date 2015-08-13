# Esto es para reemplazar en los nombre de todos los archivos 
# de una carpeta los espacios en blanco por _.

for i in * 
do
    if test -f "$i" 
    then
       echo "Doing somthing to $i"
    fi
done

#

first="I love Suzy and Mary"
second="Sara"
first=${first/Suzy/$second}

tmp=$i
tmp=${tmp/ /_}


x="    This    is      a      test   "
echo "${x// /}"
### replace all spaces with * ####
echo "${x// /*}"
 
Sample outputs:

Thisisatest
****This****is******a******test***
