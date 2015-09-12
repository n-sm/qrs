fu <- function(f,v){
    if(length(v) != 3) stop("v debe estar en R^3\n")
    x = v[1];
    y = v[2];
    z = v[3];
    f(x,y,z)
}

p1 <- function(x,y,z) -2*x+-6*y+3*z
p2 <- function(x,y,z) 3*x-2*y+z
v1 <- c(1/11,0,41/4)

mcd <- function(x,y) {
    it <- min(x, y)
    for (i in rev(seq_len(it))) {
        if(x%%i + y%%i == 0) return(i)
    }
}
