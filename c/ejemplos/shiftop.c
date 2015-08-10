#include <stdio.h>

int main() 
{
  int i, j;
  i = 145;
  printf("\ni = %d\n", i);
  j = i >> 15;
  printf("\nj = %d\n", j);
  printf("\ni = %d\n", i);

  return 0;

}
