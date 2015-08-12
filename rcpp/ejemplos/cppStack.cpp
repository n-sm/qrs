// Ejemplo de "C++ The Complete Reference" de Herb Schildt, p.273.

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]


#define SIZE 100

class stack {
  int stck[SIZE];
  int tos;
public:
  void init();
  void push(int i);
  int pop();
};

stack mystack;

