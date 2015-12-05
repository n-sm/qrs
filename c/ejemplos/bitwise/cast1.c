#include <limits.h>
#include <stdio.h>

#define sign(x) (-(int) LASTBIT((unsigned int) ((int)x)))
int main()
{
  int i, j;
  
  for ( i=9; i > -10; i--)
    printf("(unsigned int) %d es %u\n", i, (unsigned int) i);

  printf("UINT_MAX es %u\n", UINT_MAX);
  return 0;
}
 
