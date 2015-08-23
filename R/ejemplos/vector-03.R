## Algebra CBC, practica 1 ejercicio 13 c.
##
## Encontrar un vector ortogonal a A y B donde:
## A = (1, 2, -1)
## B = (2, 0, 1)

ejemplo <- function()
{ # usamos la relacion 1 -> .1
    par (mfrow = c(1, 1))
    arrows3D(0,0,0, .2, 0, .2, col='red')
    arrows3D(0,0,0, .1, .2, -.1, add=TRUE)
    arrows3D(0,0,0, .1, -.1, -.1, add=TRUE, col='blue')
}
