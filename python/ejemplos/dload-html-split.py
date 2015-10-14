#! /usr/bin/env python
# esto es como un wget -qO- URL

import urllib.request
import sys
import re


url = sys.argv[1] #'http://www.example.com/'
response = urllib.request.urlopen(url)
html = response.read()
#print(html)
try:
    text = html.decode('utf-8')
except:
    text = html.decode('latin-1')

lista=re.split("<", text)

for record in lista:
#    print(record)
    res=re.search('a title.*\$', record)
    if res:
        print(record[res.start():])
        break
    
#print(text)
