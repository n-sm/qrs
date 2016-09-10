#include <stdio.h>

int isp(char *string);

int main(int argc, char *argv[]) {
  char * string = argv[1];
  printf("string: %s\n", string);
  char * respuesta =  isp(string) ? "True" : "False";
  printf("\nEs palindromo?\n Respuesta: %s", respuesta);
  return 0;
}


int isp(char *string)
{
  if (!string) return 1;
  char * p, * q;
  q = p = string;
  while(*q)
    q++;
  int ctr = 0;
  while( *p++ == *(--q) ) {
    printf("%d:\t*p: '%c'\t *q: '%c'\n",
	   ++ctr, *(p-1), *q);
    if ( p >= q ) return 1;
  }

  return 0;
}

  
/*
  while(*q)
    q++;
  q--;

  while( *p == *q ) {
    printf("*p: %c, *q: %c\n", *p, *q);
    if ( p++ >= q-- ) return 1;
*/  
    
