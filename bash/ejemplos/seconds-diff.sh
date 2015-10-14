

getsec () {
    
    time=$(date +"%T")
    time=(${time//:/ })
    echo ${time[2]}
}

time1=$(getsec)
sleep 2
time2=$(getsec)
echo $(( time2 - time1)) 
