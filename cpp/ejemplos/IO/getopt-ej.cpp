#include <iostream>
#include <stdio.h>
//#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main( int argc, char *argv[] )  
{
  char c;

  while ((c = getopt (argc, argv, "abc")) != -1) {
    switch (c) {
    case 'a':
      std::cout << "caso a\n";
      return 0;
      break;
    case 'b':
      std::cout << "caso b\n";
      return 0;
    case 'c':
      return 0;
      break;
    case '?':
      if (optopt == 'd' || optopt == 'o') {
      }
      else if (isprint (optopt)) {
	fprintf (stderr, "Unknown option `-%c'.\n", optopt);
      }
      else
	fprintf (stderr,
		 "Unknown option character `\\x%x'.\n",
		 optopt);
      return 1;
    default:
      abort ();
    }
  }
  // termina getopt
  
   
  return 0;
}


