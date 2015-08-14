#!/bin/bash
#
# Insertar una string al inicio de una linea
#
# http://superuser.com/questions/246837/how-do-i-add-text-to-the-beginning-of-a-file-in-bash
#
# USO: insert... LINEA STRING FILE
#

declare -i LINE=$1
declare STR=$2
declare FILE=$3

sed "${LINE}s/^/${STR}/" "$FILE"

# para cambiarlo en el mismo archivo, usar:
#
# sed -i "${LINE}s/^/${STR}/" "$FILE"
#
# la opcion -i indica que se haga en el mismo archivo.
#

# para indicar tambien una columna
#
# sed -r "${LINE}s/^.{${COL}}/&${STR}/" "$FILE"
#
# la opcion -r indica usar regexp
