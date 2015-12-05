// https://graphics.stanford.edu/~seander/bithacks.html

#include <stdio.h>
#include <limits.h>

#define intsign(x)						\
  (+1 |	-(int)((unsigned int) ((int)x) >> sizeof(int)*CHAR_BIT - 1))

#define abs(x) \
  ((x + (x >> sizeof(int)*CHAR_BIT-1)) ^ (x >> sizeof(int)*CHAR_BIT-1))

int main()
{
  int i;
  for(i = 50; i > -51; i--)
    printf("abs(%d) es %d\n", i, abs(i));

  

  return 0;
}
