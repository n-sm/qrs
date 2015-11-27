import urllib.request, re

def getHtml(url, isFile=False):
    '''getHtml: Obtiene una string de una url o archivo.'''
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
    para la función desplegarScriptTags().
    '''
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

    Devuelve un `tree' con los elementos, con los sub elementos anidados
    en sublistas.
    '''
    if type(pag) is str: print("error!, no llamar con str como arg!")
    desde = 0;
    pares = []; # pares?? que quise decir?
    currentTag = '';
    ctr = 0 # es necesario??
    for i in range(len(pag)):
        match = re.match('<([^! >]+)', pag[i], re.I)
        if not currentTag:
            if not match or re.match('meta|link', match.group(1), re.I):
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
    return dst


        
def getpag(url):

    g = getHtml(url)
    p = parseHtml(g)
    a   = agrupar(p)
    return a

#g = getpag('html1')

def ld():
    exec(open('parseHtml-w.py').read())
    
print('''

testeo: 
x = getHtml(URL)
pagina = parseHtml(x)

en 'g' ejemplo.\nPAra loadear: ld()\n\n
''')

## cada lista devuelta por parseHtml() tiene:
## elementos atomicos tales como whitespace
## otros elementos

## Creamos una clase para repersentar mejor esto.

class Docu:
    def __init__(self, pag):
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
                    print(tmpName, end="")#debug
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
        self.__dict__.update(self.tags)

def noSubLists(lista):
    for e in lista:
        if type(e) is list:
            return False
    return True

def findin(que, donde):
    '''Encuentra QUE en DONDE
    DONDE es una lista de strings
    '''
    ret = []
    if not noSubLists(donde):
        print("Error: DONDE no debe tener sublistas")
        return 0
    for i in range(len(donde)):
        if not isinstance(donde[i], str): continue
        if re.match('<%s[^a-z]' % que, donde[i], re.I):
            ret.append([i, donde[i]])
    return ret

def atoms(htmltree):
    ret = []
    if noSubLists(htmltree): # htmltree es atom
        return htmltree
    for i in range(len(htmltree)):
        iatomp = atoms(htmltree[i])
        if iatomp:
            ret.append(iatomp)
        else:
            print("13456")
    return ret
        
    return ret

def flatten(lista):
    '''
    Combina todos los elementos de las sublistas del la list original
    en una única lista de elementos atomicos. Esta funcion imita otra
    hecha mas natulamente en elisp (ver tef).
    '''
    if type(lista) is not list:
        return [lista]
    if len(lista) is 0:
        return []
    if len(lista) is 1:
        return flatten(lista[0])
    elem = lista[0]
    resto = lista[1:]
    if type(elem) is list:
        return flatten(elem) + flatten(resto)
    return [elem] + flatten(resto)

#def searchTree(tree):
#    if type(tree) is not tree:
        
class Atom():
    def parseAttr(self,string):
        tag         = False
        nombre      = False
        valor       = False
        desde       = 0
        currentName = ''
        currentVal  = ''
        dictio      = {}
        
        if string[0] is '<': tag = True
        for i in range(len(string)):
            c = string[i]
            # Esto es solo para el tag inicial.
            if tag:
                if c is ' ': tag = False
                continue
            if c is ' ': continue
            if c is '"':
                # Empieza valor:
                if not valor:
                    valor = True
                    desde = i
                    #nombre = False
                    continue
                # Cierra Valor:
                currentVal = string[desde:i]
                dictio[currentName] = currentVal
                valor = False
                nombre = False
                desde = i
                continue
            if c is '=' and not valor:
                currentName = string[desde:i]
                #desde = 0
                #nombre = False
                continue
            # Aca llega si c no es ' ' ni '"' ni '='
            # Empieza nombre:
            if not nombre:
                nombre = True
                desde = i
        return dictio
        
    def __init__(self, arg):
        # Un 'Atom' tiene una string con tag al inicio, una string
        # con cierre al final y algun contenido en el medio.
        self.tagname = None
        # self.content = None
        self.attribs = {}
        # Este if hay que sacarlo, pues lo maneja Elem.
        if type(arg) is str:
            self.string = arg 
            match = re.match('<([^! >]+) *?([^ ].*)>', arg, re.I)
            # No es Tag:
            if not match:
                self.name  = 'text'
                return
            # Es Tag:
            self.tagname = match.group(1)
            self.attribs = self.parseAttr(arg)
            #self.attribs = match.group(2)
            #self.rest = match.group(2)
            #match = re.search('([^ ]+)="(.+)"', arg, re.T)
            return

class Elem():
    def __init__(self, arg):
        self.lista = []
        self.tag
        for elm in arg:
            if type(elm) is str:
                e = Atom(elm)
                if e.tagname:
                    self.tag = e.tagname
            
                
        
