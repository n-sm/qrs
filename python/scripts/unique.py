#!/usr/bin/python

import sys, getopt

argv = sys.argv

data = sys.stdin.readlines()

ret = list()
for w in data:
    if w in ret:
        continue
    ret.append(w)

#for w in ret:
#    print (w, end="")
for w in ret:
    print (w,end="")
