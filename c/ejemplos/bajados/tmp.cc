//http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format

#include <stdio.h>      /* printf */
#include <string.h>     /* *strcat(s, ct): concatenate string ct at end of s */

#include <Rcpp.h>

using namespace Rcpp;

const char *byte_to_binary(int x)
{
  static char b[9];
  b[0] = '\0';

  int z;
  for (z = 128; z > 0; z >>= 1)
    {
      strcat(b, ((x & z) == z) ? "1" : "0");
    }

  return b;
}

// [[Rcpp::export]]
int byte2bin(int i)
{

  printf("%s\n", byte_to_binary(i));

  return 0;
}
