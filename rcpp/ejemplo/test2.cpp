#include <Rcpp.h>
using namespace Rcpp;
int suce(const int x);
// [[Rcpp::export]]
int sumaInt(const int x, int y) {
  if (x < 0 || y < 0) return(-1);
  else if (x == 0) return(y);
  else return(sumaInt(x-1, suce(y)));
}
          
int suce(const int x) {
  return x+1;
}
