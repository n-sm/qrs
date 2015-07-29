#include <stdio.h>
#include "ploop.h"


int main(int arc, char *argv[])
{
  char *line;
  do {
  printf(".\\ ");
  line = ploop();
  printf("ret de wrongParen: %d\n",  wrongParen(line));
  free (line);
  } while (1);

  return 0;
}
