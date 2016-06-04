resto.recu <- function(a, d)
{
    if (a < d) return (a)
    return (resto(a-d, d))
}

resto <- function(a, d)
{
    if(a < d) return(a)
    tmp <- a
    while (a - d >= d) {
        a <- a - d
    }
    cat("a:",a,"d:",d,"\n")
    if(a==d) return(0)
    a
}
