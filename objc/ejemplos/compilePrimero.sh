#!/bin/bash
# gcc -o primero -I/usr/include/GNUstep/Foundation/ -lobj primero.m
gcc $(gnustep-config --objc-flags) primero.m $(gnustep-config --base-libs)
