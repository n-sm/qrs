# include <stdio.h>

char string[256];
int main(void)
{
  printf("Pulse una tecla cualquiera, y luego Enter. \n");
  scanf("%s", string);
  while((string[1] != 0) || (string[0] != 'a' && string[0] != 'b' && string[0] != 'c'))
    {printf("Debe elegir a, b, o c, pero ingreso %c. Intente de nuevo:\n", string);
     scanf("%s", string);
    }
  printf("\nLa tecla es:\n%s\n", string);
  return 0;
}
