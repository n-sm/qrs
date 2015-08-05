miexp <- function(x, exact=.00001) {

    xnSnfact <- function(x,n) {
        ## x a la n sobre n factorial.
        numerador <- rep(x,n)
        denominador <- n:1
        prod(numerador/denominador)
    }

    getn <- function(x, exact) {
        n <- 1
        while( xnSnfact(x, n)  > exact ) n <- n+1
        n
    }
    n <- getn(x, exact = exact)

    sum( sapply(0:n, function(arg) xnSnfact(x,arg)))
}
