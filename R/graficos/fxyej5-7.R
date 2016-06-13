x <- y <- seq(-5,5,by=0.1)

f <- list(
    function(x,y) (2*x + 1 - y)^2,
    function(x,y) x^2 - y^2 - x*y + 3*x + x*y + 1,
    function(x,y) 10*x^2 + 10*y^2 + 12*x*y, 2*x + 6*y + 1,
    function(x,y) exp(1+x^2+y),
    function(x,y) sqrt(x^2 + y^2) + x*y,
    function(x,y) (x -y)^2 + 1 + 2*(x-y),
    function(x,y) exp(x-y)*(x^2-2*y^2),
    function(x,y,z) x*y + z^2,
    function(x,y,z) 2*x^2+y^2+z^2-x*y+2*x*z+z,
    function(x,y) x^2-2*x*y+y^4-y^5,
    function(x,y) 1/(1+x^2))


# persp(outer(x,y,f),shade=T)
