#!/bin/bash
#

declare STRfrom=$1
declare STRto=$2
declare FILE=$3

sed "s/${STRfrom}/${STRto}/g" "$FILE"

