import urllib.request, re

def getHtml(url, isFile=False):
    # Obtiene una string de una url o archivo.
    if isFile:
        try:
            with open(url, 'r', encoding='utf-8') as f:
                html = f.read()
        except:
            with open(url, 'r', encoding='latin-1') as f:
                html = f.read()
    else:
        if(not re.match(r'https?://', url)):
            url       = 'http://' + url
            response  = urllib.request.urlopen(url)
            charset   = response.headers.get_param('charset')
            htmlBytes = response.read()
            html = htmlBytes.decode(charset)
    return(html)

def parse1(html):
    # obtiene pares que delimitan una string.
    ctr=0
    pares = []
    desde = 0
    str0 = False
    str1 = False
    script = False
    for i in range(len(html)):
        c = html[i]
        if not str0 and c is '\'': str0 = True
        if not str1 and c is '"': str1 = True
        if str0 and c is '\'' and html[i-1] is not '\\': str0 = False
        if str1 and c is '"' and html[i-1] is not '\\': str1 = False
        if not desde: desde = i
        if str0 or str1: continue
        ## aca empieza
        if c is '<' and html[i + 1] is not ' ':
            if script:
                if not re.match('</script',html[i:i+8],re.I): continue
                else:
                    script = False
                    continue
            # elemento en nivel = 0:
            if not ctr:
                hasta = i
                if desde < hasta: pares.append([desde, hasta])
                # marco inicio de elemento:
                desde = i
            ctr += 1
            if re.match('<script', html[i:i+7],re.I): script = True
        if c is '>' and not script:# and html[i - 1] is not ' ':
            if not ctr: continue
            ctr -= 1
            # cierra un elemento:
            if not ctr:
                # marco  fin de elemento.
#                desde = i + 1
                hasta = i + 1
                # lo que sigue podria mejorarse quiza, es para
                # agrego bordes de elemento a la lista.
                pares.append([desde, hasta])
                desde = i + 1
    return pares

def substr(string, pares):
    # devuelve una pagina, en estado 'atomico'
    return [string[par[0]:par[1]] for par in pares]

def desplegarScriptTags(pagina):
    ret = []
    for e in pagina:
        m = re.match('(<script[^>]*?>)(.*?)(</script>)',e,re.I|re.S)
        if m:
            g = list(m.groups())
            if '' in g:
                g.remove('')
            ret.extend(g)
        else: ret.append(e)
    return ret
        
def getpag(url):
    g = getHtml(url,1)
    p = parse1(g)
    s = substr(g,p)
    d = desplegarScriptTags(s)
    return d

g = getpag('html1')

print('''
funciones definidas:
getHtml(url, isFile=0)
parse1(html)
substr(string, pares)

g = getpag(url):

''')

def agrupar(pag, fstIndx=0):
    desde = 0; pares = []; currentTag = ''; ctr = 0 # es necesario??
    for i in range(len(pag)):
        match = re.match('<([^! >]+)',pag[i])
        if not match:
            if not currentTag: pares.append(i)
            continue
        # Hubo match.
        m = match.group(1)
        if m[0] is not '/':
            # Es beggining.
            if not currentTag:
                currentTag = m
                desde = i
                ctr += 1
            continue
        # En end.
        if m == "/%s" % currentTag:
            ctr -= 1
            if ctr == 0:
                hasta = i
                #if test
                #recursive = agrupar(pag[desde + 1:hasta], desde +1)
                #recursive[0:0] = [desde + fstIndx + 1]
                #recursive.append(hasta + 1 + fstIndx) #ok!
                #pares.append(recursive)
                #else
                pares.append([desde + fstIndx, hasta + fstIndx])
                #endif
                currentTag = ''
    return pares

def mchi(string):
    return re.match('<([^ >]+)', string)

def mchf(string):
    return re.match('<([^ >]+)', string)

def agrupar2(pag, fstIndx=None):
    desde = 0; pares = []; currentTag = ''; ctr = 0 # es necesario??
    if not fstIndx: fstIndx = 0
    for i in range(len(pag)):
        match = re.match('<([^! >]+)',pag[i])
        if not match:
        ####__PARES
            if not currentTag: pares.append(i + fstIndx + 1)
            continue
        # Hubo match.
        m = match.group(1)
        if m[0] is not '/':
            # Es beggining.
            if not currentTag:
                currentTag = m
                desde = i
                ctr += 1
            continue
        # En end.
        if m == "/%s" % currentTag:
            ctr -= 1
            if ctr == 0:
                hasta = i
                #if test
                recursive = agrupar2(pag[desde + 1:hasta], desde + 1)# este ok,
                #tiene que estarlo si no no haria el anidamiento
                recursive[0:0] = [desde + fstIndx]
                recursive.append(hasta + 1 + fstIndx) #ok!
                pares.append(recursive)
                #else
                #pares.append([desde + fstIndx, hasta + fstIndx])
                #endif
                currentTag = ''
    return pares


def listaOK(l):
    i = 0
    length = len(l)
    while ( i + 1 < length ):
        if l[i] + 1 is not l[i + 1]:
            return False
        i += 1
    return True

def agrup(pag):
    if type(pag) is str: print("error!, no llamar con str como arg!")
    desde = 0; pares = []; currentTag = ''; ctr = 0 # es necesario??
    for i in range(len(pag)):
        match = re.match('<([^! >]+)', pag[i])
        if not currentTag:
            if not match:
                pares.append(pag[i])
            else:
                m = match.group(1)
                if m[0] is not '/':
                    currentTag = m
                    desde = i
                    ctr += 1
                    print("match beg")
            continue
        # En end.
        if not match: continue
        m = match.group(1)
        if m == "/%s" % currentTag:
            ctr -= 1
            if ctr == 0:
                hasta = i
                #if test
                if desde > hasta:
                    pares.append(pag)
                    print("desde: %s, hasta:%s" % (desde, hasta))
                    continue
                recursive = agrup(pag[desde + 1:hasta])
                print("pag desde(%s): %s" % (desde,  pag[desde]))
                print("pag hasta(%s): %s" % (hasta, pag[hasta]))
                recursive[0:0] = [pag[desde]]
                recursive.append(pag[hasta])
                pares.append(recursive)
                #else
#                pares.append([pag[desde],pag[hasta]])
                #endif
                currentTag = ''
    return pares
        
        
### old
