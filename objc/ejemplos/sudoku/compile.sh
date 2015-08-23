#!/bin/bash
gcc $(gnustep-config --objc-flags) sudoku6.m $(gnustep-config --base-libs)
