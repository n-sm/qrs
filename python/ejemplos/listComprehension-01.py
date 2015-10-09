#! /usr/bin/env python
# Este ejemplo aplica una funcion a una lista
lista = range(25)
lista = [ x + 1 for x in lista]

# podemos hacer una funcion:
def add1(lista):
    return([x + 1 for x in lista])

