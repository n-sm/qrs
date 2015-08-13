#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int fibonacciRecu(const int x) {
  if (x < 2) return x;
  else return (fibonacciRecu(x-1)+fibonacciRecu(x-2));
}
