# include <stdio.h>
#include <stdlib.h> // esto es por el exit
char cada_rta[1], respuestas[374], c, nombre[299], str[256], e;
char nombre_archivo[] = "preguntas.txt";

int i, d, n = 256, count = 0;
FILE *ifp, *ofp;

int main(void)

{
  ifp = fopen(nombre_archivo, "r");
  for (e = getc(ifp); e != EOF; e = getc(ifp))
        if (e == '\n') // Increment count if this character is newline
            count = count + 1;
  fclose(ifp);
  ifp = fopen(nombre_archivo, "r");
  for(i = 0; i <= count - 1; i = i + 1)
    {
    printf("%d.", i+1);
    fgets(str, 256, ifp);
    puts(str);
    scanf("%s", cada_rta);
    if (cada_rta[0] == 's')
      exit(1);
    while((cada_rta[1] != 0) || (cada_rta[0] != 'a' && cada_rta[0] != 'b' && cada_rta[0] != 'c'))
      {
	printf("     Debe elegir a, b, o c, pero ingreso %s.\nIntente de nuevo: \n", cada_rta);
	scanf("%s", cada_rta);
      }
    printf("\nLa tecla es: %s\n", cada_rta);
    c = cada_rta[0];
    respuestas[( 2 * i) - 1] = ',';
    respuestas[2 * i] = c;
    cada_rta[0] = '\0';
    }
  printf("Ingrese su nombre: ");
  scanf("%s", nombre);
  printf("\n\n\n\n\n Las respuestas fueron: %s\n\n", respuestas);
  ofp = fopen("respuestas.txt", "w");
  fprintf(ofp, "%s,%s", nombre, respuestas);
  return 0;
}
