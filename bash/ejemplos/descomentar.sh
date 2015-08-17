#! /bin/bash
# Este script sirve para quitar de un archivo de texto
# todo comentario de la forma '//' ode la forma '/* ,,, */'


sed -e 's:/\*.*\*/::g' -e 's://.*$::g' -e 's:/\*.*?\*/:\n:g' $1  | perl -0777  -pe 's:/\*(.|\n)*?\*/:\n:g'
