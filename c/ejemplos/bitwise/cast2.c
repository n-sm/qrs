#include <limits.h>
#include <stdio.h>

#define sign(x)							\
  (+1 |	-(int)((unsigned int) ((int)x) >> sizeof(int)*CHAR_BIT - 1))

int main()
{
  long i;
  
  for ( i=9l; i > -10l; i--)
    printf("(int) %ld es %d\n", i, (int) i);

  printf("(int) %ld es %d\n", LONG_MAX, (int) LONG_MAX);
  
  printf("UINT_MAX es %u\n", UINT_MAX);
  printf("UINT_MAX es %ld\n", LONG_MAX);
  // este caso no funciona:
  printf("sign LONG_MAX es: %d\n", sign(LONG_MAX));
  return 0;
}
 
