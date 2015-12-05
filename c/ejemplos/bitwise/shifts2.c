#include <stdio.h>
#include <limits.h>

#define LASTBIT(x) x >> (sizeof(x) * CHAR_BIT - 1)

int main()
{
  int i, j;
  int loopfin = 999;// por si hago mal el for;
  int lugares = sizeof(int) * CHAR_BIT;

  printf("CHAR_BIT es %d\n", CHAR_BIT);
  printf("sizeof(int) * CHAR_BIT es: %d\n", lugares);

  i = 1;
  printf(" (1 << 31) | 1  es %d\n", (1 << 31) | 1);
  
  printf("\n");
  return 0;
}
