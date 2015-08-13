/*
calloc significa "contiguous allocation".
malloc significa memory allocation"".


*/

# include <stdio.h>
# include <stdlib.h>
# define N 127

char *a, *q, *r, arr[N];
int n, i, j = 0, x;
char c;

int main(void)
{
  printf("\n");


  for(i = 0, j = 0;(c = getchar()) != '\n'; ++i, ++j) {
    arr[i] = c;
    }

  printf("%c\n", arr[0]);

  for(x = 0; x < j; ++x) {
     printf("%c", arr[x]);
  }
  /*
    while(c = getchar() != '\n') {
    arr[i] = c;
    ++i;
    ++j;
  }

 

  printf("\nj es %d\ni es %i\n", j, i);  
  */
  /*  c =  getchar();
  arr[1] = c;
  c =  getchar();
  arr[2] = c;


  printf("\narr[0] es %c", arr[0]);
  printf("\narr[1] es %c", arr[1]);
  printf("\narr[2] es %c", arr[2]);
  */
  printf("\n");

 
 return 0;
}
