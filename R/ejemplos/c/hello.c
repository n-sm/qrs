#include <R.h>

void helloN(int *n)
{

  for (int i = 0; i < *n; i++)
    Rprintf("Hello, world!\n");

}
