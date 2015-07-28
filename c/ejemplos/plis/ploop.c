#include "ploop.h"
/* <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024
*/
char* ploop()
{ // http://stephen-brennan.com/2015/01/16/write-a-shell-in-c/
  int bufsz = BUF_SIZE;
  int pos = 0;
  int c;
  char *buf = malloc(bufsz * sizeof(char));
  if (!buf) {
    fprintf(stderr, "error de memoria\n");
    exit(1);
  }
  while (1) {
    c = getchar();
    if ( c == EOF || c == '\n') {
      buf[pos] = '\0';
      return buf;
    }
    else buf[pos] = c;
    pos++;
    if ( pos >= bufsz ) {
      bufsz += BUF_SIZE;
      buf = realloc(buf, bufsz);
      if (!buf) {
    fprintf(stderr, "error de memoria\n");
    exit(1);
      }
    }
  }
}
