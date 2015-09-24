!/bin/bash

# Este ejemplo de:
# http://stackoverflow.com/questions/5626374/while-read-line-do-and-grep-problems/5626412#5626412
# muestra como mostrar las lineas de un archivo (FILE2) que contengan alguna de las
# palabras listadas en otro (FILE1).

declare FILE1=$1
declare FILE2=$2

<<<<<<< HEAD
oldIFS=$IFS
=======
olsIFS=$IFS
>>>>>>> 04717e9e4cfc25bfd42fb7474371377671dcb216

while IFS= read -r LINE; do 
  grep "$LINE" $FILE2
done < $FILE1

IFS=$oldIFS

IFS=$oldIFS


# en una linea:
# while read -r LINE; do "$LINE"; done < $FILE1

