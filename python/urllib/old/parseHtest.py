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

def desplegarScriptTags(pagina):
    ret = []
    for e in pagina:
        m = re.match('(<script[^>]*?>)(.*?)(</script>)',e,re.I)
        if m:
            g = list(m.groups())
            if '' in g:
                g.remove('')
            ret.extend(g)
        else: ret.append(e)
    return ret

def substr(string, pares):
    return [string[par[0]:par[1]] for par in pares]

def getTags(pagina, tag):
    # Falta resolver el caso de <script> que viene dado
    # en una unica string.
    ret = []
    subret = []
    match = False
    for i in range(len(pagina)):
        if match:
            if re.match("</%s" % tag, pagina[i]):
                subret.append(pagina[i])
                ret.append(subret)
                match = False
                continue
            subret.append(pagina[i])
        if re.match("<%s" % tag, pagina[i]):
            subret = []
            subret.append(pagina[i])
            match = True
            continue
    return ret

def reagruparTags(pagina):
    ## esta falta corregir...
    ret = []
    subret = []
    currentTag = ''
    for i in range(len(pagina)):
        m = re.match('<([^ >]+)',pagina[i])
        if not m:
            subret.append(pagina[i])

            continue
        if re.match('!DOCTYPE', m.group(1), re.I):
            ret.append(subret)
            ret.append(pagina[i])
            subret=[]
            continue
        if not currentTag:
            currentTag = m.group(1)
            ret.append(subret)
            subret = []
            subret.append(pagina[i])
            continue
        if m.group(1) == 'link' or m.group(1) == 'meta':
            if not currentTag:
                ret.append(subret)
                subret = []
                ret.append(pagina[i])
            else:
                subret.append(pagina[i])
            continue
        if m.group(1) == "/%s" % currentTag:
#            print(3)
#            # junto el elemento en subret:
            subret.append(pagina[i])
#            # llamo recursivamente reagrupatTags:
            recret = reagruparTags(subret[1:-1])
            tempret = []
            tempret.append(subret[0])
            tempret.extend(recret)
            tempret.append(subret[-1])
##            print("subretlen: %s" % len(subret[1:-1]))
##            recret.insert(0,"***")
##            recret.append("***")
##            subret = ['*=*', recret, '=*=']
            ret.append(tempret)
            subret = []
            recret = []
            currentTag = ''
            continue
#        # default
#        # match == T != !DOCTYPE != link; currenTag == T; != /%s
        subret.append(pagina[i])
    return ret
        
def getpag(url):
    g = getHtml(url,1)
    p = parse1(g)
    s = substr(g,p)
    r=reagTags(s)
    return r

def testt(url):
    g = getHtml(url,1)
    p = parse1(g)
    s = substr(g,p)
    r=test(s)
    return r

print('''
funciones definidas:
getHtml(url, isFile=0)
parse1(html)
desplegarScriptTags(pagina)
substr(string, pares)
getTags(pagina, tag)
reagruparTags()

getpag(url):
testt(url)
''')


def test(pagina):
    ## esta falta corregir...
    ret = []
    ret1 = []
    ret2 = []
    subret = []
    currentTag = ''
    for i in range(len(pagina)):
        m = re.match('<([^ >]+)',pagina[i])
        if not m:
            ret1.append(pagina[i])
        else:
            ret2.append(pagina[i])
    ret.append(ret1)
    ret.append(ret2)
    return ret

def reagTags(pagina):
    ret = []
    subret = []
    currentTag = ''
    for i in range(len(pagina)):
        m = re.match('<([^ >]+)',pagina[i])
        if not m:
            subret.append(pagina[i])
            continue
        if not currentTag:
            currentTag = m.group(1)
            if subret:
                ret.append(subret)
                subret = []
            subret.append(pagina[i])
            continue
        if m.group(1) == "/%s" % currentTag:
            return m.group(1)
#            print(3)
#            # junto el elemento en subret:
            subret.append(pagina[i])
#            # llamo recursivamente reagrupatTags:
#            recret = reagruparTags(subret[1:-1])
#            tempret = []
#            tempret.append(subret[0])
#            tempret.extend(recret)
#            tempret.append(subret[-1])
##            print("subretlen: %s" % len(subret[1:-1]))
##            recret.insert(0,"***")
##            recret.append("***")
##            subret = ['*=*', recret, '=*=']
            ret.append(subret)
            subret = []
            recret = []
            currentTag = ''
            continue
#        # default
#        # match == T != !DOCTYPE != link; currenTag == T; != /%s
        subret.append(pagina[i])
    return ret
