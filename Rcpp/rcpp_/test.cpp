/* Ejemplo. Chapter 8 p104 Dirk Eddelbuettel
*/
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int foo(int n)
{
  int pow = 1;
  for (int i = 0; i < n; i++)
    pow *= 2;
  return pow;
}


