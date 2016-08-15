#!/usr/bin/python

import sys, getopt

filename = sys.argv[-1]
argv = sys.argv[1:]

print("argv: ", argv)

try:
    opts, args = getopt.getopt(argv, 'r' , ['reverse'])
except getopt.GetoptError:
    print('esec [-r] <inputfile>')
    sys.exit(2)

print(opts, args)    

