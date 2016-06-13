tablita <- function(mod, pot)
{
    restos <- 1:(mod-1)
    ret <- integer()
    for (i in (1:pot))
    {
        pots <- restos^i %% mod
        ret <- rbind(ret, pots)
    }
    colnames(ret) <- paste("a =", restos)
    rownames(ret) <- paste("a", 1:pot, sep="^")
    as.data.frame(ret)
}
