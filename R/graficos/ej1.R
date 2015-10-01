
puerta.cocina <- .7
anchoDorm <- 3
alturaGarage <- 3

A <- c( anchoDorm + .45, 1.3 )
B <- c( A[1]-2.09 , A[2] )
C <- c( 0, 2.93 )
D <- c( 0, 14.12+.15 )
E <- c( .3+5.7+.15+1+2.75, D[2])
F <- c( E[1], 10.35 )
G <- c( 10.94, .3+4+.15+1.5+.15+3.45)
H <- c( G[1] , G[2]-3.45 )
I <- c( E[1]-2.75 , H[2] )
J <- c( I[1] , 4.3 )
K <- c( A[1]+1 , J[2] )
L <- c( A[1]+1 , A[2])
M <- c( .2+2.35 , 5.77+.1)
N <- c( A[1] , A[2] )

puntos <- as.data.frame(rbind(A, B, C, D, E, F, G, H, I, J, K, L))
names(puntos) <- c("x","y")

Ap <- c( A[1]-.15 , A[2]+.3 )
Bp <- c(  B[1]+.15 , B[2]+.3 )
Cp <- c(  .3      , C[2]+.15 )
Dp <- c(  D[1]+.3  , D[2]-.3 )
Ep <- c(  E[1]-.15 , D[2]-.3 )
Fp <- c(  F[1]-.15 , F[2]-.075 )
Gp <- c(  G[1]-.15 , G[2]-.075 )
Hp <- c(  H[1]-.15 , H[2]+.15 )
Ip <- c(  I[1]-.15 , I[2]+.15 )
Jp <- c(  J[1]-.15 , J[2]+.15 )
Kp <- c(  K[1]-.15 , K[2]+.15 )
Np <- c(  K[1]-.15 , A[2] )

puntosp <- as.data.frame(rbind(Ap, Bp, Cp, Dp, Ep, Fp, Gp, Hp, Ip, Jp, Kp, Np))
names(puntosp) <- c("x","y")

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
###sinExp


script.dir <- dirname(sys.frame(1)$ofile)
##png(paste(script.dir, "plano.png", sep="/"), width=210, height=297, units="mm", res=300)
dev.new(width=6, height=11) ## esto en lugar de la linea prcedente

plot.new()
plot.window( c(-.05,12), c(-.05,15))

### paredes externas
lineas(puntosp)
lineas(puntos)
### paredes internas
##pared vertical1
segments(N[1],N[2],N[1],D[2]-3)
segments(N[1]-.15, N[2]+.3, N[1]-.15, D[2]-3-.15)
##pared vertical2
segments  (I[1],I[2]+.15,  I[1],D[2]-.3)
segments  (I[1]-.15,I[2]+.15,  I[1]-.15,D[2]-.3)
##pared vertical3
segments  (M[1],M[2],  M[1],M[2]+1.5)
segments  (M[1]-.15,M[2],  M[1]-.15,M[2]+1.5)
##pared horiontal1
segments  (N[1],D[2]-3,  .3,D[2]-3)
segments  (N[1]-.15,D[2]-3-.15,  .3,D[2]-3-.15)
## pared horizontal 2
segments  (N[1]-.15,D[2]-6.75,  .3,D[2]-6.75)
segments  (N[1]-.15,D[2]-6.9,  .3,D[2]-6.9)
## pared horizontal 3
segments  (N[1]-.15,D[2]-6.75-1.65,  .3,D[2]-6.75-1.65)
segments  (N[1]-.15,D[2]-6.9-1.65,  .3,D[2]-6.9-1.62)
####%%%% medidas
text (A[1]+.4,A[2]+.1, "1m", cex=.5)
text (4,D[2]-.4, "6,7m", cex=.5)
text (E[1]-1.5,D[2]-.4, "2,75m", cex=.5)


text(.2,D[2]-1.6, "2,7m", srt=90, cex=.5)
text (2,D[2]-3.25, "3,4m", cex=.5)
text (5.2,D[2]-3.25, "3m", cex=.5)
text(.2,D[2]-5, "3,5m", srt=90, cex=.5)
text(I[1]-.22,D[2]-5, "11,52m", srt=90, cex=.5)
text(G[1]-.22,D[2]-6.25, "3,45m", srt=90, cex=.5)
text (1.6,D[2]-7.05, "2,35m", cex=.5)
text (3,D[2]-7.05, "0,9m", cex=.5)


text (-.2,15+1.3, "15--", cex=.5)
text (-.2,10+1.3, "10--", cex=.5)
text (-.2,5+1.3, "5--", cex=.5)
text (-.2,1.3, "0--", cex=.5)

#mostrar.puntos()


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

puerta(A[1], A[2], 1 - 0.15)
puertav(D[1]+.3, D[2]-.3, .8 - 0.15, vertical = T)


### la mesada:
puertaCocina <- .7
xMesada <- D[1]+.3
yMesada <- D[2]-3
anchoMesada <- alturaGarage - puertaCocina
profMesada <- .62
distMesadaCocina <- .4

mesada <- function(x) {
    segments(xMesada, yMesada, xMesada, yMesada + anchoMesada )
    segments(xMesada +profMesada, yMesada+alturaGarage-puertaCocina,
             xMesada+profMesada,yMesada+profCocina)

 # (\xMesada+\profMesada+\distMesadaCocina,\yMesada+\profCocina);
 # %% la bacha
 # \def\anchoBacha{.66};
 # \cuad{\xMesada+.175}{\yMesada+\anchoMesada-.3-\anchoBacha}{\anchoBacha}{.35};
}


anchoCocina <- .55
profCocina <- .6
xCocina <- D[1] + .3 + profMesada + distMesadaCocina
yCocina <- D[2] - 3

cocina <- function(x) {
    rect(xCocina, yCocina, yCocina+anchoCocina, xCocina+profCocina)
#  \cuad{\xCocina}{\yCocina}{\profCocina}{\anchoCocina}
#  \draw (\xCocina+.15, \yCocina+.15) circle(.075);
#  \draw (\xCocina+.4,  \yCocina+.15) circle(.075);
#  \draw (\xCocina+.4,  \yCocina+.45) circle(.075);
#  \draw (\xCocina+.15, \yCocina+.45) circle(.075);
}

##mesada(1)
##cocina(1)
dev.off()
