uno <- function(n) n^2 + n + 1
dos <- function(n) n^3 + n + 4

resto <- function(n) dos(n) %% uno(n)
coci <- function(n) dos(n) %/% uno(n)
