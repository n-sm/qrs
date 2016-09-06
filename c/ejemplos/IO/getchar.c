# include <stdio.h>
# include <stdlib.h>
# define N 9999

int i, j, array[N];
char c;

int main(void)
{
  printf("Ingrese texto: ");


  for(i = j = 0; (c = getchar()) != '\n'; ++i, ++j) {
    array[i] = c;
    }


  for(i = 0; i < j; ++i) {
     printf("%c", array[i]);
  }
  
  printf("\n");
 return 0;
}
