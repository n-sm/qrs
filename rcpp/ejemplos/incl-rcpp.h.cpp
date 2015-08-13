/* Ejemplo. Chapter 8 p104 Dirk Eddelbuettel
*/
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
 SEXP foo( SEXP xs, SEXP ys) {
  NumericVector x(xs);
  NumericVector y(ys);
  return ifelse(1, xs, xy);
}


