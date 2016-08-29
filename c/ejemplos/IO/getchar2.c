# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(void)
{
  FILE *ofp;
  int i, k, j;
  char c, *p, *q, *array[5];
  
  printf("Ingrese texto: ");

  for(j = 0; j < 5; ++j) {

  for(i = 0; (c = getchar()) != '\n'; ++i) {
    p = calloc(i + 1, sizeof(char));
    for(k = 0; k < i ;++k)
       p[k] = q[k];
    p[i] = c;
    q = calloc(i + 1, sizeof(char));
    for(k = 0; k < i+1 ;++k)
       q[k] = p[k];
  }
  /*
  printf("\n");
  for(k = 0; k < i; ++k) 
     printf("%c", p[k]);
  free(p); free(q);
  printf("\n");
  */
  array[j] = calloc(strlen(p) + 1, sizeof(char));
  strcpy(array[j], p);

  ofp = fopen("texto.txt", "w");
  // for(i=0;i<5;++i)
    fprintf(ofp, "%s", array[0]);

  }
 return 0;
}
