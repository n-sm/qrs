add1 <- function(x) {
    assign(as.character(quote(x)), x+1, envir = .GlobalEnv)
    }


