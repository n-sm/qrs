#include "stdio.h"
#include "stdlib.h"

int main(int argc, char ** argv)
{

  unsigned char my_char = 0xAA;
  long long input;
  int what_bit_i_am_testing = 0;

  printf("n args: %d", argc);
  if (argc > 1)
  {
      input = atoll(argv[1]);
      if(input > 255)
      {
	  printf("El numero debe ser entre 0 y 255");
	  return 0;
      }
      my_char = (char) input;
  }
  
  while (what_bit_i_am_testing < 8) {
    if (my_char & 0x01) {
      printf("bit %d is 1\n", what_bit_i_am_testing);
    }
    else {
      printf("bit %d is 0\n", what_bit_i_am_testing);
    }

    what_bit_i_am_testing++;
    my_char = my_char >> 1;

    nota:
    /*
    Lo que hacemos es ir comparando el primer bit (0x01 es 00000001)
    y vamos corriendo el char my_char de a una posicion con ">>".
    */
  }
}
