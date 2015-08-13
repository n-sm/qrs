# include <stdio.h>

void swap(int *, int*);

int main(void)
{
  int i = 3, j = 5;
  printf("i es %d y j es %d", i, j);
  swap(&i, &j);
  printf("\n Pero ahora, i es %d y j es %d\n", i, j);
  //  printf("%d  %d\n", i, j);
  return 0;
}

void swap(int *p, int *q)
{
  int tmp;

  tmp = *p;
  *p = *q;
  *q = tmp;
}
