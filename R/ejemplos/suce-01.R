a. <- function(n)
{
    if (n == 1) return (2)
    if (n == 2) return (8)
    s1 <- a.(n-2) * (n+1)/2
    s2 <- a.(n-1) * (n+2)
    s1 + s2
}


cota <- function(n)
{
    2*n*factorial(n)
}
