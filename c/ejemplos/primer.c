# include <stdio.h>

char a;
int main(void)
{
  printf("Pulse una tecla cualquiera, y luego Enter. \n");
  scanf("%c", &a);
  printf("\nLa tecla es: %c \n", a);
  return 0;
}
