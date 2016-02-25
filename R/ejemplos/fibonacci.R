fibonacci <- function(n)
{
##    (1/(sqrt(5))) * ((1 + sqrt(5)) /2)^n - (1/sqrt(5)) * ((1 - sqrt(5))/2)^n
    q <- sqrt(5)
    (1/q * ((1+q)/2)^n - (1/q) * ((1 - q)/2)^n)
}



fib.recursive <- function(n)
{
   if (n == 1 || n == 2) return (1)
   else return ( fib1(n-1) + fib1(n - 2))
}



fib.iterative <- function(n)
{
    if (n == 1 || n == 2) return (1)
    else
    {
        n_1 <- 1
	n_2 <- 1
        for (i in 1:(n-2)) {
	    tmp <- n_2
	    n_2 <- n_2 + n_1
	    n_1 <- tmp
	    }
	return(n_2)
    }
}