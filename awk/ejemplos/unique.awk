## usar con 'ls -l'. Si no cambiar $3 por $0.
BEGIN { 
    ## FS="[ \t]"
    arr[0] = ""
}

{
    caso = $3
    for (v in arr)
	if (caso == arr[v]) next
    arr[length(arr) + 1] = caso
}

END {
    for (val in arr) print arr[val]
}
