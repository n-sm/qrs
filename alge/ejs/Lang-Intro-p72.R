A <- matrix(c(2,3,-1,1,
              1,4,2,-2,
              -1,1,3,-5,
              1,2,3,4),
            byrow=TRUE,ncol=4)

U <- matrix(rep(0, 4*4), nrow=4)

Uf <- function(r,s) {
    U[r,s] <- 1
    U
}

E <- diag(1,4,4)

Ef <- function(r,s) {
    E <- diag(1,4,4)
    E[r,s] <- 1
    E
}
