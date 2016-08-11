#! /usr/bin/env python

import urllib.request
import sys, getopt
from bs4 import BeautifulSoup as bs

def main(argv):

    contentOn = False
    numOn = False
    
    html = ""
    try:
        opts, args = getopt.getopt(argv, 'f:w:cn')
    except getopt.GetoptError:
        print('getlinks [-f <filename> | -w <url> ]')
        sys.exit(2)

     
    if len(argv) == 0:
        html = sys.stdin.read()

    for opt, arg in opts:
        if opt == "-f":
            with open (arg, 'r') as f:
                html = f.read()

        elif opt == '-w':
            response = urllib.request.urlopen(arg)
            html = response.read()

        elif opt =='-c':
            contentOn = True
        elif opt == '-n':
            numOn = True
                
    soup = bs(html,"html.parser")

    href_tags = soup.find_all(href=True)
    
    contador = 1
    enumerador = 0
    print("\n\nla len de href tags", len(href_tags))
    for i,h in enumerate(href_tags):
        link = h.get('href')
        ##if link == "": continue
        if contentOn:
            if len(h.contents) != 0:
                cont = str(h.contents[0])
                print("\n{}".format(breakLines(cont.strip())))
            else:
                print("\nSin texto")
        if numOn:
            print("{}: ".format(contador), end="")
            contador += 1

        if enumerador == 0 \
           or link != href_tags[enumerador-1].get('href'):
            print(link)
        enumerador += 1


    
def breakLines(string, atMost=80):
    l = atMost - 1
    if(len(string) <= atMost): return string
    else:
        while (string[l] != " "):
            l -= 1
            if(l == 0): return("String de mas de 80 sin espacios?")

        primera = string[:l]
        segunda = breakLines(string[l+1:], atMost)
        return(primera + "\n" + segunda)


if __name__ == "__main__":
    main(sys.argv[1:])
