# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define TY4DE short int
//# define TYPR d

int main(void) 
{
  TY4DE i, j;
  for(i = 1, j = 0; i > j ; ++i, ++j)
    ;
  printf("\nTY4DE max: %d \n", j);  
  for(j = 0, i = 1; j < i;--i, --j)
    ;
  printf("\nTY4DE min: %d \n", i);  

  return 0;

}
