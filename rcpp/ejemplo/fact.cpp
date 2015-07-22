/* Esto es solo un ejemplo. eEn si no tiene utilidad.
   Para usarlo desde R escribir:
   sourceCpp('fact.cpp')
*/
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
long fact(int  n) {
  if (n == 0 || n == 1) return(1);
  else return(fact(n - 1) * n);
}

