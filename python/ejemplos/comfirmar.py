#! /usr/bin/env python
# de la Guia de Python de Van Rossum

def confirmar(indicador, intentos=4, queja='Si o no!!'):
    while 1:
        respuesta=raw_input(indicador)
        if respuesta in ('si', 's'): return 1
        if respuesta in ('no', 'n'): return 0
        intentos -= 1
        if intentos < 0: raise IOError, 'Usuario rechazado'
        print queja
        
