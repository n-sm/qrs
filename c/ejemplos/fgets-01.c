#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FORM_SZ 999

int main (void) {

  char *formula = malloc (MAX_FORM_SZ);
  if (formula == NULL) {
    printf ("Sin memoria\n");
    return 1;
  }

  printf("Escriba la formula:\n");

  fgets (formula, MAX_FORM_SZ, stdin);

  /* Remove trailing newline, if there. */
  int largo = strlng(formula);
  if ((largo > 0) && (formula[largo - 1] == '\n'))
    formula[largo - 1] = '\0';

  printf("La formula es:\n%s\n", formula);
  printf("form length:%d\n",strlng(formula));
  printf("formula[largo] es: %c", formula[largo-1]);
  return 0;
}

