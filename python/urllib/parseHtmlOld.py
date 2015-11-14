import urllib.request, re

def getHtml(url, isFile=False):
    if isFile:
        try:
            with open(url, 'r', encoding='utf-8') as f:
                html = f.read()
        except:
            with open(url, 'r', encoding='latin-1') as f:
                html = f.read()
    else:
        if(not re.match(r'https?://', url)):
            url = 'http://' + url
            response = urllib.request.urlopen(url)
            htmlBytes = response.read()
            try:
                html = htmlBytes.decode('utf-8')
            except:
                html = htmlBytes.decode('latin-1')
    return(html)

def parse1(html):
    ctr=0
    pares = []
    cmnt = False
    cmntpp = False
    str0 = False
    str1 = False
    for i in range(len(html)):
        c = html[i]
        if c is '/' and html[i + 1] is '*': cmnt = True
        if c is '/' and html[i - 1] is '*': cmnt = False ; #print("FAFAFF")
        if c is '/' and html[i - 1] is not '/' and html[i + 1] is '/':
            cmntpp = True
        #    print(html[i-9:i+9])
        if not str0 and c is '\'': str0 = True
        if not str1 and c is '"': str0 = True
        if str0 and c is '\'' and html[i-1] is not '\\': str0 = False
        if str1 and c is '"' and html[i-1] is not '\\': str0 = True
        if c is '\n':
            cmntpp = False
            #            print("asdasd")
            #        if cmnt: print("c")
            #        if  cmntpp: print("cpp")
            if cmnt or cmntpp or str0 or str1:
                continue
## aca empieza
        if c is '<' and html[i + 1] is not ' ':
            # elemento en nivel = 0:
            if not ctr:
                # marco inicio de elemento:
                desde = i
            ctr += 1
        if c is '>':# and html[i - 1] is not ' ':
            ctr -= 1
            # cierra un elemento:
            if not ctr:
                # marco  fin de elemento.
                hasta = i + 1
                # agrego bordes de elemento a la lista.
                pares.append([desde, hasta])
    return pares

def substr(string, pares):
    return [string[par[0]:par[1]] for par in pares]
