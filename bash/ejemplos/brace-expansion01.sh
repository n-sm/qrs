#!/bin/bash
echo este es un ejemplo del uso de '{ }'.
echo
echo Ejemplo uno: 'a{b,c}'
echo  a{b,c}
echo
echo Ejemplo dos: '{1..7}'
echo {1..7}
echo
echo Ejemplo tres: 'x{1..7}'
echo x{1..7}
echo
echo
echo Ejemplo cuatro: 'echo {1{1,2,3},2{1,2,3},3{1,2,3}}'
echo echo {1{1,2,3},2{1,2,3},3{1,2,3}}
echo
echo Ejemplo cinco: 'name{1..9}'
echo echo name{1..9}
echo
echo Ej. seis: '{a..k}'
echo {a..k}
echo
echo Ej siete: 'echo 1{{a..k},}'
echo echo 1{{a..k},}
echo
echo Ej ocho: '{0..9}{a..f}'
echo {0..9}{a..f}
echo
echo Ej nueve: 'echo {{0..9},{a..f}}'
echo {{0..9},{a..f}}
echo
echo Ej diez '{{0..9},{a..f}}{{0..9},{a..f}}'
echo {{0..9},{a..f}}{{0..9},{a..f}}

