#!/bin/bash

#### http://stackoverflow.com/questions/450799/shell-command-to-sum-integers-one-per-line

awk ' { s+=$1 } END { print s } '
