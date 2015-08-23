# include <stdio.h>


char cada_rta[256], respuestas[374], c;
int i;
int main(void)
{
  for(i = 0; i <= 5; i = i + 1)
    {
    printf("%d.\n Elija 'a', 'b' o 'c' y luego presione Enter. \n", i+1);
    scanf("%s", cada_rta);
    while((cada_rta[1] != 0) || (cada_rta[0] != 'a' && cada_rta[0] != 'b' && cada_rta[0] != 'c'))
      {
	printf("     Debe elegir a, b, o c, pero ingreso %s.\nIntente de nuevo: \n", cada_rta);
	scanf("%s", cada_rta);
      }
    printf("\nLa tecla es: %s\n", cada_rta);
    c = cada_rta[0];
    respuestas[( 2 * i) - 1] = ',';
    respuestas[2 * i] = c;
    }

  printf("\n\n\n\n\n Las respuestas fueron: %s\n\n", respuestas);

  return 0;
}
