#!/usr/bin/python

import sys, getopt

filename = sys.argv[-1]
argv = sys.argv[1:]

print("argv: ", argv)

try:
    opts, args = getopt.getopt(argv, 'r:st' , ['rev=', 'sin'])
except getopt.GetoptError:
    print('error')
    sys.exit(2)

print(opts, args)    



