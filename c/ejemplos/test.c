
#include <stdio.h>

int sucesor(int x);
main()
{
  double i = 3.2;
  double a = i/2;
  int b = 445 % 33;
  double c = 445.1 % 1.0;

  printf("This is a native C program.\n");


   printf("i/2 es %f \n i  2 es %d\n", a, b);
  printf("i/2 es %f \n ", a);
  printf("b  es %d \n ", b);
  printf("c  es %f \n ", c);
  
    return 0;
}



int sucesor(int x) {
  return x + 1;
}
