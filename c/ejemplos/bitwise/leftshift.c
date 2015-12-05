// Cuando se hace un left shift >>, el signo
// se mantiene.

#include <stdio.h>

#define sign(x) (-(int) LASTBIT((unsigned int) ((int)x)))
int main()
{
  printf("-1 en 32 bit binario se representa: 11111111\n");
  printf("si hacemos -1 >> 1, el lugar de la izquiera es\n");
  printf("ocupado nuevamente por un 1, no cambiando el re-\n");
  printf("sultado. ej: -1 >> 1 es %d\n", -1 >> 1);
  
  return 0;
}
