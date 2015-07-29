#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
double suma(const double x, double y) {
  if (x < 1 && x > -1) return(y+x);
  else if (x < 0) return suma(x+1, y-1);
  else return suma(x-1, y+1);
}
