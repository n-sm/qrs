ls -l | awk '  ~/10/ &&  ~ /^[0-9]+$/ &&  ~ /jun/{ print -bash}'
ls -l | awk -v x=0 ' { if ( ~ /root/) x++; if (x) print  } '
