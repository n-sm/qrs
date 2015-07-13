/*
Este ejemplo muestra como se usa el '->' en C.
Fuente: Al Kelley, p.411 [217].
 */

#include <stdio.h>


typedef struct {
  double re;
  double im;
}  complex;

void add(complex *a, complex *b, complex *c) // a = b + c
{
  a -> re = b -> re + c -> re;
  a -> im = b -> im + c -> im;
}

main()
{

  complex sumando1 = {23, 45};
  complex sumando2 = {13.1, -2.4};
  complex resultado;
  add(&resultado, &sumando1, &sumando2);

  printf("sumando1 = %f + %fi\n", sumando1.re, sumando1.im);
  printf("sumando2 = %f + %fi\n", sumando2.re, sumando2.im);
  printf("resultado = %f + %fi\n", resultado.re, resultado.im);

}

