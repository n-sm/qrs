#! /bin/bash

cvt 1024 768 1366
informacion=$( cvt 1024 768 1366 | tail -1 | cut -d' ' -f2- )
primer=$( echo $informacion | { read first rest ; echo $first ; } )
xrandr --newmode $informacion

xrandr --output VGA-0 --mode $primer

