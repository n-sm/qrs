### Algunos ejemplos.
### mas info http://adv-r.had.co.nz/Rcpp.html
cppFunction('
int add(int x, int y) {
int sum = x + y;
return sum;
}')

cppFunction('
int fact(int n) {
  if (n == 0 ) return(1);
  else return(factorial(n - 1) * n);
}')


RcppExport SEXP foo( SEXP xs, SEXP ys) {
    Rcpp::NumericVector x(xs);
    Rcpp::NumericVector y(ys);
    return ifelse( x < y, x*x, -(y*y) ) ;
}
