cociente.resto <- function(a, d)
{
    ## a: dividendo
    ## d: divisor
    if(a >= 0 && d > 0)
    {
        k <- 0
        r <- a
        while(r >= d)
        {
            r <- r - d
            k <- k + 1
        }
        return(c(k=k, r=r))
    }

    if(a >= 0 && d < 0)
        return(cociente.resto(a,-d) * c(-1,1))

    if(a < 0 && d > 0)
        return(-1*cociente.resto(-a,d) + c(-1, d))

    if(a < 0 && d < 0)
    {
        cr <- cociente.resto(-a, -d)
        if(cr["r"] == 0)
            return(cr * -1)
        cr * c(1, -1) + c(1, -d)
    }


}
