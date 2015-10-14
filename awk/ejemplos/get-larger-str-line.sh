
# con awk es mucho mas rapido!!!

countAWK () {
cat $1 | awk ' BEGIN { max=0 } length($1) > max \
  { max=length($1) } \
 END { print max } '
}


# con bash, mas lento

countSH () {
    declare -i MAX=0
    for name in $( cat $1 )
    do
	if [[ ${#name} -gt $MAX ]]
	then
	    MAX=${#name}
	fi
    done
    echo $MAX
}
    

