#include "stdio.h"

int main() 
{
  int i, j, k, l;
  unsigned int ui = 7;
  short int si = 7;
  char c = 7;
  i = 7;
  printf("i: %d\t~i: %d\t~i: %d\n", i,~i,i);
  printf("ui: %d\t~ui :%d\n", ui, ~ui);
  printf("si: %d\t~si :%d\n", si, ~si);
  printf("c: %d\t~c: %d\n", c, ~c);

  j = 3;
  k = 5;
  printf("j: %d, k: %d, j & k: %d\n", j, k, j&k);
  k = 2;
  printf("j: %d, k: %d, j & k: %d\n", j, k, j&k);
  l = 23;
  printf("l: %d, 1 >> l: %d\n", l, 1  >> l);
  printf("l: %d, 2 >> l: %d\n", l, 2  >> l);

  int a = 60;

 printf("\nNumber is Shifted By 1 Bit : %d",a << 1);
 printf("\nNumber is Shifted By 2 Bits : %d",a << 2);
 printf("\nNumber is Shifted By 3 Bits : %d\n",a << 3);
}

