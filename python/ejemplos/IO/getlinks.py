#! /usr/bin/env python

import urllib.request
import sys, getopt
from bs4 import BeautifulSoup as bs

def main(argv):

    soup = getSoup(argv)
    href_tags = soup.find_all(href=True)
    print(soup)
    for a in href_tags:
        print(a)


def getSoup(argv):
    html = ""
    try:
        opts, args = getopt.getopt(argv, 'f:w:')
    except getopt.GetoptError:
        print('getlinks [-f <filename> | -w <url> ]')
        sys.exit(2)

     
    if len(argv) == 0:
        print("len arg es 0")
        html = sys.stdin.readlines()

    else:
        for opt, arg in opts:
            if opt == "-f":
                with open (arg, 'r') as f:
                    html = f.read()
                    
            elif opt == '-w':
                response = urllib.request.urlopen(arg)
                html = response.read()
                
    soup = bs(html,"html.parser")
    return(soup)
                
if __name__ == "__main__":
    main(sys.argv[1:])
