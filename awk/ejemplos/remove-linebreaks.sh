awk '{printf "%s",$0} END {print ""}' file

# remove breaklines
awk '{printf "%s",$0} ' index.html 
