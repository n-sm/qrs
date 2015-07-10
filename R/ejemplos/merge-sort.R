### Cormen 2.3.1 merge sort algorith

mimerge <- function(A, p, q, r) {
    out <- A
    n1 <- q - p + 1
    n2 <- r - q
    L <- out[p:q]
    R <- out[(q+1):r]
    L[n1 + 1] <- Inf
    R[n2 + 1] <- Inf
    i <- 1
    j <- 1
    for (k in p:r) {
        if (L[i] <= R[j]) {
            out[k] <- L[i]
            i <- i+1
        }
        else {
            out[k] <- R[j]
            j <- j+1
        }
    }
    out
}

mergeSort <- function(A, p, r) {
    if (p < r) {
        q <- floor((p+r)/2)
        A <- mergeSort(A, p, q)
        A <- mergeSort(A, q+1, r)
        A <- mimerge(A, p, q, r)
    }
    A
}
