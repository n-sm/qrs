#!/bin/bash
declare FILE=$1
gcc $(gnustep-config --objc-flags) $FILE $(gnustep-config --base-libs)
