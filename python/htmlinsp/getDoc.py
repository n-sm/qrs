import urllib.request
import re


def getHtml(url, isFile=False):
    '''getHtml: Obtiene una string de una url o archivo.'''
    html = None
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
        #
        # Otro dia habria que emprolojar esto:
        charset   = response.info().get_content_charset()
        if not charset:
            charset = response.headers.get_param('charset')
            if charset: print("response.headers.get_param('charset')")
        else: print("anduvo response.info().get_content_charset()")
        htmlBytes = response.read()
        if charset:
            html = htmlBytes.decode(charset)
        if not html:
            print("No pudo obtenerse charset de:")
            print(url)
            print("probando utf-8 y latin-1")
            try:
                html = htmlBytes.decode('utf-8')
                if html: print("Se uso utf-8")
            except:
                html = htmlBytes.decode('latin-1')
                if html: print("Se uso latin-1")
        if not html:
            print("aborting")
            return
    return(html)
