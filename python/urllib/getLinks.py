import urllib.request, re

def getLinks(url):
    if(not re.match(r'http://', url)):
        url = 'http://' + url
    response = urllib.request.urlopen(url)
    htmlBytes = response.read()
    try:
        html = htmlBytes.decode('utf-8')
    except:
        html = htmlBytes.decode('latin-1')
    links = re.findall(r'<a .*?</a>', html, re.S|re.I)
    return(links)


class Link:
    def __init__(self, link):
        tmp = re.search(r'href="(.*?)"',link, re.I)
        self.href = tmp.group(1) if tmp else None
        tmp = re.search(r'>(.*?)</a>',link, re.I|re.S)
        self.contenido = tmp.group(1) if tmp else None
        tmp = re.search(r'title="(.*?)"',link, re.I)
        self.title = tmp.group(1) if tmp else None
        self.entero = link

class Notas:
    def __init__(self, links):
        self.links = []
        for link in links:
            try:
                tmplink=Link(link)
                if (tmplink.href and not tmplink.href in self.links):
                    self.links.append(Link(link))
            except:
                pass
    def hrefs(self): return [li.href for li in self.links]
    def contenidos(self): return [li.contenido for li in self.links]
    def titles(self): return [li.title for li in self.links]
    def verLinks(self): return [li.entero for li in self.links]
    def len(self): return (len(self.links))
    def noticias(self, minlen = 25):
        tmp = []
        for li in self.contenidos():
            if ((len(li) > minlen) and not re.search(r'[<>/]', li)):
                tmp.append(li)
        return(tmp)
    def nots(self,lines=10):
        j = 0
        for i,n in enumerate(self.noticias()):
            j += 1
            if (j < lines): print('{}: {}'.format(i,n))
            else:
                j=0
                inp=input('Press Enter...')
                if (inp == 'q'): break
    
def leer(pagina):
    return(Notas(getLinks(pagina)))

print('''
o:      n=leer('www....')
''')
