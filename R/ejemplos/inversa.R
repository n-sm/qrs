inverse <- function (f, lower = -100, upper = 100) {
   function (y) uniroot((function (x) f(x) - y), lower = lower, upper = upper)[1]
}