getsec () {
    nanosecs=`date +"%s%N"`
    length=${#nanosecs}
    echo ${nanosecs:0:$((length - 9))}.${nanosecs:$((length - 9)):$length}
}
