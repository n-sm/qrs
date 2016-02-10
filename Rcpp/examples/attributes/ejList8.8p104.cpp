/* Esto es solo un ejemplo. eEn si no tiene utilidad.
   Para usarlo desde R escribir:
   sourceCpp('fact.cpp')
*/
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
SEXP foo( SEXP xs, SEXP ys) {
  NumericVector x(xs);
  NumericVector y(ys);
  return ifelse( x < y, x*x, -(y*y) );
}
