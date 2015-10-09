sum () {
    
    [[ $# -eq 0 ]] &&\
	>&2 echo "Debe proporcionarse al menos un argumento." &&\
    return 1
	    
    declare -i suma=0
    for i in "$@"
    do
	(( suma += i ))
	#suma=$(( suma + i ))
    done
    echo $suma
}

prod () {

    [[ $# -eq 0 ]] &&\
	>&2 echo "Debe proporcionarse al menos un argumento." &&\
    return 1
    
    declare -i producto=1
    for i in "$@"
    do
	(( producto *= i ))
	#suma=$(( suma + i ))
    done
    echo $producto
}

echo "sum, prod defined"

