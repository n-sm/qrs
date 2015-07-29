#!/bin/sh
# Linux users have to change $8 to $9
# http://www.grymoire.com/Unix/Awk.html#uh-0

awk '
BEGIN { print "File\tOwner" }
{ print $9, "\t", $3}
END { print " - DONE -" }
'
