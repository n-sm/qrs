/* Este ejemplo se basa en es siguiente;
   http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
   arg: int x
   val: character representing x in bit formatt
   also: it prints val with C's printf.
*/

#include <stdio.h>      /* printf */
#include <string.h>     /* *strcat(s, ct): concatenate string ct at end of s */
#include <Rcpp.h>

#define NBITS 32

using namespace Rcpp;

// [[Rcpp::export]]
std::string byte2bin(unsigned long int x)
{

  static char b[NBITS + 1];
  b[0] = '\0';

  unsigned long int pow = 1;
  for (int i = 1; i < NBITS; i++)
    pow *= 2;

  for (unsigned long int z = pow; z > 0; z >>= 1)
    {
      strcat(b, ((x & z) == z) ? "1" : "0");
    }

  printf("%s\n", b);
  std::string stdb = b;
  return stdb;
}
