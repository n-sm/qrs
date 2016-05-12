S <- function(n, k)
{
    if (n < k) return (0)
    if (n == k) return(1)
    if (k == 0) return(0)
    if (k == 1) return(1)
    if (k == 2) return( 2^(n-1) - 1)
    k*S(n-1, k) + S(n-1, k-1)
}
