#include <stdio.h>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define rec0(X, Y) (X) ? rec1((X) - 1) : X
#define rec1(X) (X) ? rec0((X) - 1) : X

int main()
{
  int ret;
  ret = rec1(9);
  printf("ret is: %d", ret);
}
