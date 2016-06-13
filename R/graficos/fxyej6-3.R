x <- y <- seq(-1,1,by=0.1)


f <- function(x,y)
    sqrt(x^2+y^2-1)

persp(outer(x,y,f),shade=T)
