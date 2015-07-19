// este ejemplo modifica una de Al Kelley, p.424ss [224]

#include <stdio.h>


typedef union int_or_float {
  int i;
  float f;
} number;

int main(void) 
{

  int i = 1;
  int *pi = &i;
  number n;
  number * ptr;
  n.i = 4444;
  ptr = &n;
  printf("n : i: %10d      f:%16f.10e\n", n.i, n.f);

  n.f = 4444.0;
  printf("n : i: %10d      f:%16f.10e\n", n.i, n.f);
  printf("================\n");

  printf("ptr : i: %10d      f:%16f.10e\n", ptr->i , (ptr->f) + 1);

  number *p02;
  p02 = (number *) ptr;
  printf("p02 : i: %10d      f:%16f.10e\n", p02->i , (p02->f) + 1);

  (number *) pi;

  printf("pi : i: %10d      f:%16f.10e\n", ((number *) pi)->i , ((number *) pi)->f);

  number * opt = ((number *) pi) + 1;
  printf("opt: i: %10d      f:%16f.10e\n", opt ->i, opt->f);


  return 0;
}
