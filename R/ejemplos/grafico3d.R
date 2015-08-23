ejemplo <- function()
{
    par (mfrow = c(1, 2))
    arrows3D(x0 = runif(10), y0 = runif(10), z0 = runif(10),
             x1 = runif(10), y1 = runif(10), z1 = runif(10),
             colvar = 1:10, code = 1:3, main = "arrows3D", colkey = FALSE)
}
