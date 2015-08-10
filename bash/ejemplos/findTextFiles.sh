#!/bin/sh
#
# http://stackoverflow.com/questions/4767396/linux-command-how-to-find-only-text-files

declare FOLDER=$1

find "$FOLDER" -type f -exec grep -Iq . {} \; -and -print | head -33
