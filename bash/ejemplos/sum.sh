sum() {
    declare -i sum
    for n in $@
    do
	let  sum+=$n
    done
    echo $sum
}
