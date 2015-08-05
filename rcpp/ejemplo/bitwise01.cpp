// http://stackoverflow.com/questions/2611764/can-i-use-a-binary-literal-in-c-or-c

#include <boost/utility/binary.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <Rcpp.h>

using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
int binary() {
  unsigned short b = BOOST_BINARY( 10010 );
  char buf[sizeof(b)*8+1];
  printf("hex: %04x, dec: %u, oct: %06o, bin: %16s\n", b, b, b, itoa(b, buf, 2));
  cout << setfill('0') <<
    "hex: " << hex << setw(4) << b << ", " <<
    "dec: " << dec << b << ", " <<
    "oct: " << oct << setw(6) << b << ", " <<
    "bin: " << bitset< 16 >(b) << endl;
  return 0;
}
