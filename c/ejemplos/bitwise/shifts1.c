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
  //  printf(" %d >> 31 es: %d\n", c,  c >> 1);
  for(j=1; j<32; j++)
    printf("1 << %d es %16d\t%16d >> %d es %d\n",
	   j, 1 << j, 1 << j, j, (1 <<j) >> j );
//  for (i = 0; c < 256, --loopfin; c++)
//    printf(" %d >> 31 es: %d\n", c, c >> 31);

  if(!loopfin) printf("loopfin llego a 0");
  
  printf("\n");
  return 0;
}
