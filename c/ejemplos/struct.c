/*
Este ejemplo muestra como se puede usar struct junto con typedef
de tres formas distintas y equivalentes.
Tambien se muestra una forma de inicializar un struct mas breve.

 */
#include <stdio.h>

struct carta1 {
  int num;
  char palo;
};


typedef struct carta1 carta2;

typedef struct {
  int num;
  char palo;
} carta3;

main()
{

  struct carta1 c1;
  c1.num = 1;
  c1.palo = 'c';

  carta2 c2;
  c2.num = 2;
  c2.palo = 'c';

  carta3 c3;
  c3.num = 3;
  c3.palo = 'c';
 
 // La que sigue es otra forma de inicializar.
  carta3 c4 = { 4, 'c'};

  printf("c1 tiene num: %d y palo %c\n", c1.num, c1.palo);
  printf("c2 tiene num: %d y palo %c\n", c2.num, c2.palo);
  printf("c3 tiene num: %d y palo %c\n", c3.num, c3.palo);
  printf("c4 tiene num: %d y palo %c\n", c4.num, c4.palo);


}
