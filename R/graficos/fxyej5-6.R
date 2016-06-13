x <- y <- seq(-5,5,by=0.1)

f <- function(x,y)
{
    x^4 + y^4 -2*(x-y)^2
}

persp(outer(x,y,f),shade=T)
