#!/bin/bash

## ESTE EJEMPLO MUESTRA COMO USAR EL OUTPUT DE UN COMANDO
## COMO INPUT DE UN SCRIPT VIA PIPE.

# http://superuser.com/questions/747884/how-to-write-a-script-that-accepts-input-from-a-file-or-from-stdin
# Some explanation of the script:
#
# [ $# -ge 1 -a -f "$1" ] - If at least one command line argument ($# -ge 1) AND (-a operator) the first argument is a file (-f tests if "$1" is a file) then the test result is true.
#
# && is the shell logical AND operator. If test is true, then assign input="$1" and cat $input will output the file.
#
# || is the shell logical OR operator. If the test is false, then commands following || are parsed. input is assigned to "-". cat - reads from the keyboard.
# 
# Summarising, if the script argument is provided and it is a file, then variable input is assigned to the file name. If there is no valid argument then cat reads from the keyboard.

[ $# -ge 1 -a -f "$1" ] && input="$1" || input="-"

cat $input
