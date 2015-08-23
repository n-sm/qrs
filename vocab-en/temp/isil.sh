#!/bin/bash
#
# Insertar una string al inicio de una linea
#
# USO: insert... LINEA STRING FILE
#
declare -i LINE=$1
declare STR=$2
declare FILE=$3

cat "$FILE"  | sed "${LINE}s/^/${STR}/"
