#! /bin/bash

#find . -iname "*.odt" -print0 | xargs -0 printf "%s"

# este anduvo
for FILE in $( find . -iname "*.sh" -print0 | xargs -0 printf "%s\n" ) ; do 


#este no anda
#for FILE in $( find . -iname "*.sh" -print0  ) ; do 


printf "%s\n" $FILE
cat $FILE
done
