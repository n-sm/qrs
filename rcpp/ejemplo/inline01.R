src <- '
Rcpp::NumericVector xa(x);
return xa;'

f <- cxxfunction(signature(x="numeric"),
                 body=src,
                 plugin="Rcpp")

g <- cxxfunction(signature(x="numeric"),
                 body='
std::cout << "asd";
Rcpp::NumericVector xa(x);
return xa;',
                 plugin="Rcpp")

h <- cxxfunction(signature(),
                 body='std::cout << "Hello World!!" << std::endl;',
                 plugin="Rcpp")



h2 <- cfunction(signature(),
                 body='printf("HW");')



h3 <- cfunction(signature(),
                "
SEXP ret = PROTECT(allocVector(REALSXP, 1));
REAL(ret)[0] = 2;
UNPROTECT(1);
return ret;")

add <- cfunction(c(a = "integer", b = "integer"), "
  SEXP result = PROTECT(allocVector(REALSXP, 1));
  REAL(result)[0] = asReal(a) + asReal(b);
  UNPROTECT(1);

  return result;
")
#====

src <- '
Rcpp::NumericVector xa(a);
Rcpp::NumericVector xb(b);
int n_xa = xa.size(), n_xb = xb.size();

Rcpp::NumericVector xab(n_xa + n_xb - 1);
for (int i = 0; i < n_xa; i++)
for (int j = 0; j < n_xb; j++)
xab[i + j] += xa[i] * xb[j];
return xab;
'
fun <- cxxfunction(signature(a = "numeric", b = "numeric"),src, plugin = "Rcpp")

R> fun(1:3, 1:4)
[1] 1 4 10 16 17 12
With one assignment to the R
