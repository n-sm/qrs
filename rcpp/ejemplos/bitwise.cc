#include <stdio.h>
#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::export]]
void foo()
{
  printf("sizeof(int) es %d\n", sizeof(int));

  printf("0b00000101 es  en %%x: %x\n", 0b00000101);
  printf("~0b00000101 es  en %%x: %x\n", ~0b00000101);

  printf("0b00000101 & 0b00000101 es en %%x: %x\n", 0b00000101 & 0b00000101);
  printf("0b00000100 & 0b00000101 es en %%x: %x\n", 0b00000100 & 0b00000101);
  printf("0b00000101 | 0b00000101 es en %%x: %x\n", 0b00000101 | 0b00000101);
  printf("0b00000100 | 0b00000101 es en %%x: %x\n", 0b00000100 | 0b00000101);
  printf("0b00000101 ^ 0b00000101 es en %%x: %x\n", 0b00000101 ^ 0b00000101);
  printf("0b00000100 ^ 0b00000101 es en %%x: %x\n", 0b00000100 ^ 0b00000101);


}

