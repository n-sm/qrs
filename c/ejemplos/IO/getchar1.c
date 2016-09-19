# include <stdio.h>
# include <stdlib.h>
# define N 9999

int main(void)
{
  int i, k;
  char c, *p, *q;
  
  printf("Ingrese texto: ");

  for(i = 0; (c = getchar()) != '\n'; ++i) {
    p = calloc(i + 1, sizeof(char));
    for(k = 0; k < i ;++k)
       p[k] = q[k];
    p[i] = c;
    q = calloc(i + 1, sizeof(char));
    for(k = 0; k < i+1 ;++k)
       q[k] = p[k];
  }

  printf("\n");
  for(k = 0; k < i; ++k) 
     printf("%c", p[k]);
    free(p); free(q);
    printf("\n");
 return 0;
}
