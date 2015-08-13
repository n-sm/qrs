#! /bin/bash

find . -iname "*\.txt" -print0 | xargs -0 rm
