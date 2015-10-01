
linea <- function(x,y) segments(x[1],x[2],y[1],y[2])

lineas <- function( df ) {
    for(i in 2:dim(df)[1]) linea(as.double(df[i-1,]) ,as.double(df[i,]))
}
## hay que hacerla, pero para data.frames no list!
pared <- function(lista, ancho = .15) {
    lineas(lista)
    l <- lista
    for(i in 1:length(l)){
        l[[i]][1] <- l[[i]][1] + ancho
    }
    lineas(l)
 }

mostrar.puntos <- function() {
    for(i in 1:dim(puntos)[1])  {
        text(puntos[i,1],puntos[i,2],row.names(puntos)[i])
    }
}
texto <- function(v, texto) {
    text(v[1],v[2],texto)
}



### todo esto de las puertas va a haber que corregirlo
puerta <- function( x, y, ancho, pared = .15, horizontal = T) {
    anp <- .05 # el ancho de la puerta.
    ang1 = 0
    ang2 = 90
    draw.arc(x, y, radius = ancho , deg1 = ang1, deg2 = ang2)
    ancho <- ancho - .1
    segments(x, y, x + ancho, y, col = "white")
    segments(x, y, x, y + ancho)
    segments(x + anp, y, x+ anp, y + ancho)
    segments(x, y, x + anp, y)
    segments(x, y + ancho, x + anp, y + ancho)
}


puertav <- function( x, y, ancho, pared = .15, vertical = FALSE) {
    anp <- .05 # el ancho de la puerta.
    if (vertical) {
        ang <- c(-90, 0)

    } else {
        ang <- c(0, 90)
        ancho <- ancho - .1 # para que encaje el dibujo.
    }

    draw.arc(x, y, radius = ancho , deg1 = ang[1], deg2 = ang[2])
    segments(x, y, x + ancho, y )
    segments(x , y - anp, x + ancho , y - anp)
    segments(x, y - anp, x , y )
    segments(x + ancho , y, x + ancho , y - anp)
    if(vertical) ancho <- ancho - .1
    segments(x, y, x, y  - ancho , col = "white")
}

mesada <- function(x) {
    segments(xMesada, yMesada, xMesada, yMesada + anchoMesada )
    segments(xMesada +profMesada, yMesada+alturaGarage-puertaCocina,
             xMesada+profMesada,yMesada+profCocina)

 # (\xMesada+\profMesada+\distMesadaCocina,\yMesada+\profCocina);
 # %% la bacha
 # \def\anchoBacha{.66};
 # \cuad{\xMesada+.175}{\yMesada+\anchoMesada-.3-\anchoBacha}{\anchoBacha}{.35};
}

cocina <- function(x) {
    rect(xCocina, yCocina, yCocina+anchoCocina, xCocina+profCocina)
#  \cuad{\xCocina}{\yCocina}{\profCocina}{\anchoCocina}
#  \draw (\xCocina+.15, \yCocina+.15) circle(.075);
#  \draw (\xCocina+.4,  \yCocina+.15) circle(.075);
#  \draw (\xCocina+.4,  \yCocina+.45) circle(.075);
#  \draw (\xCocina+.15, \yCocina+.45) circle(.075);
}

script.dir <- dirname(sys.frame(1)$ofile)
print(script.dir)
dev.new(width=6, height=11)

plot.new()
plot.window( c(-.05,12), c(-.05,15))

dev.off()
