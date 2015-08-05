//http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format

#include <stdio.h>      /* printf */
#include <string.h>     /* *strcat(s, ct): concatenate string ct at end of s */

#include <Rcpp.h>

using namespace Rcpp;




//Rcpp::CharacterVector
// [[Rcpp::export]]
std::string byte2bin(int x)
{
  static char b[9];
  b[0] = '\0';

  int z;
  for (z = 128; z > 0; z >>= 1)
    {
      strcat(b, ((x & z) == z) ? "1" : "0");
    }

  printf("%s\n", b);
  std::string stdb = b;
  return stdb;
}
