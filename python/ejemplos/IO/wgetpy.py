#! /usr/bin/env python
# esto es como un wget -qO- URL

import urllib.request
import sys
from bs4 import BeautifulSoup as bs

url = sys.argv[1] #'http://www.example.com/'
response = urllib.request.urlopen(url)
html = response.read()
soup = bs(html,"lxml")
    
print(soup.prettify())
