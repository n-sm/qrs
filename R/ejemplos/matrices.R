getMatList <- function(n = 0, dim=c(3,3), inset=-2:2) {
    ## Devuelve una matriz (si n=0) de dimension dim con
    ## coeficientes en inset.
    ## Si n > 0 devuelve una lista con tales matries.

    if(!n) {
        m <- matrix(sample(inset,
                           Reduce("*", dim),
                           replace=T), nrow=dim[1])
    }
    else {
        m <- list()
        for (i in 1:n) {
            m[[i]] <- getMatList(n=0, dim=dim, inset=inset)
        }
    }
    m
}

canonica <- function(n=3) {
    daf <- data.frame()
    for (i in 1:n) {
        v <- rep(0,n)
        v[i] <- 1
        daf <- rbind(daf,v)
    }
    daf <- as.matrix(daf)
    colnames(daf) <- NULL
    rownames(daf) <- NULL
    daf
}


## ej5.11
b <- matrix(c(1,1,-1,
              2,0,1,
              0,1,0), nrow=3)
b1 <- matrix(c(1,-1,1,
               1,1,0,
               0,0,1), nrow=3)
v <- c(-1,1,0,0,
       -1,2,-1,0,
       0,0,0,1,
       0,-3,0,-1)
