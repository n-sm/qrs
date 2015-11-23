import urllib.request, re

def getHtml(url, isFile=False):
    '''Obtiene una string de una url o archivo.'''
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



def delimitar(html):
    '''
Dado una string como argumento (se espera un docuento html),
devuelve una lista de pares que delimitan cada uno de los 
elementos que la componen. El caso de los scripts se deja
para la función desplegarScriptTags().'''
    
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
                # agrego bordes de elemento a la lista.
                pares.append([desde, hasta])
                desde = i + 1
    return pares

def substr(string, pares):
    ''' 
El input de esta funcion está compuesto por una string 
que contiene una pagina html y uan lista de pares que 
delimitan las partes en que se la quiere dividir.

Devuelve una pagina, en estado 'atomico'.
Esto quiere decir, cada elemento sera una string.
El objeto devuelto será una list de tales string.
'''
    return [string[par[0]:par[1]] for par in pares]

def desplegarScriptTags(pagina):
    '''
Esta función esta destinada a tratar el caso de los scripts
que, como pueden incluir characteres '<' o '>' que pueden
evitar que el parser (delimitar) cunpla su tarea, fueron 
tratados como elemento atómicos, cuando tienen una tag de 
inicio, un contenido y una de fin.
'''
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

def agrupar(pag):
    '''
Esta función recibe una pagina bajo la forma de una lista de strings,
cada una de las cuales es un elemento atómico de la misma.

Devuelve una lista con los elementos, con los sub elementos anidados
en sublistas.
'''
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
                    #print("match beg")
            continue
        # En end.
        if not match: continue
        m = match.group(1)
        if m == "/%s" % currentTag:
            ctr -= 1
            if ctr == 0:
                hasta = i
                if desde > hasta:
                    pares.append(pag)
                    continue
                recursive = agrupar(pag[desde + 1:hasta])
                recursive[0:0] = [pag[desde]]
                recursive.append(pag[hasta])
                pares.append(recursive)
                currentTag = ''
    return pares
    
def parseHtml(htmlString):
    d   = delimitar(htmlString)
    s   = substr(htmlString, d)
    dst = desplegarScriptTags(s)
    a   = agrupar(dst)
    return a

        
def getpag(url):
    g = getHtml(url,1)
    p = parseHtml(g)
    return p

g = getpag('html1')

def ld():
    exec(open('parseHtml-w.py').read())
    
print("\n\nen 'g' ejemplo.\nPAra loadear: ld()\n\n")

## cada lista devuelta por parseHtml() tiene:
## elementos atomicos tales como whitespace
## otros elementos

## Creamos una clase para repersentar mejor esto.

class Docu:
    def __init__(self, pag):
        '''
        Dar como argumento una pagina proveniente de getpag()
        '''
        self.name = None
        self.whitespace = []
        self.strings = []
        self.elts = len(pag)
        self.tags = {}
        self.t = []
        self.tg = {}
        self.untagged = []
        #print('deb')
        
        if isinstance(pag, list) and isinstance(pag[0], str):
            match = re.match('<([^ >]+)', pag[0], re.S)
            self.name = match.group(1) if match else None

        tmptags = {}
        for i in range(len(pag)):
            e = pag[i]
            if isinstance(e, list):
                tmp = Docu(e)
                tmpName = tmp.name if tmp.name else None
                if tmpName:
                    print(tmpName, end="")
                    # IF (no funciona)
                    #print(0,end="")
                    if tmpName not in self.tags.keys():
                        print(1,end="")
                        self.tags[tmpName] = tmp
                        continue
                    if not isinstance(self.tags[tmpName], list):
                        tmplist = []
                        tmplist.append(self.tags[tmpName])
                        self.tags[tmpName] = tmplist
                    self.tags[tmpName].append(tmp)
                    # ELIF (funciona)
                    #self.tags[tmpName] = tmp
                    #self.t.append(tmp)

                        
                else:
                    self.untagged.append(tmp)
                    print('untagger append')
                continue
            if isinstance(e,str):
                if re.match('^\s+$', e):
                    ## esto no sirve para nada, pero es un caso
                    ## del loop y me parecio en principio hacer
                    ## algo con esto.
                    self.whitespace.append(e)
                    continue
                if e[0] != '<':
                    self.strings.append(e)
                    continue
                #print(0)
                match = re.match('<([^/! >]+)', e)
                if match and i > 0 and i < len(pag):
                    print(0,end="")
                    tag = match.group(1)
                    #setattr(self, tag, e)
                    if tag not in self.tags:
                        print(tag, end="")
                        self.tags[tag] = []
                        self.tags[tag].append(e)
                    else:

                        print(1, end='')
                        self.tags[tag].append(e)
            
                # ELSE:
            #print('error', end='')
            
        #print("slgo del loop")
        self.__dict__.update(self.tags)


