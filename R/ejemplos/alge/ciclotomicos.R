ciclot = function(n) rep(1,n)
ciclots = function(hasta) sapply(2:hasta, ciclot)

ciclroots = function(grado)
{
    n <- grado + 1
    sapply(ciclots(n),polyroot)
}

cicIm <- function(grado)
{
    lapply(ciclroots(grado), Im)
}
