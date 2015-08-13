#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
int sumaInts(const int x, int y) {
  if (x == 0) return(y);
  else if (x < 0) return sumaInts(x+1, y-1);
  else return sumaInts(x-1, y+1);
}
