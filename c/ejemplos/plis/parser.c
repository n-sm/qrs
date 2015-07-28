#include <stdio.h>
#include <stdlib.h>


#define BUF_SIZE 1024


int wrongParen(char* s)
{
  char *p = s;
  if (*p == '\0') return 0; // mmmm '\0' es lista vacia??
  do {
    if (*p != '(' && *p != ' ') return 999;
    p++;
  } while (*p == ' ');
  int i = 0;
  int test = 0;
  for(p=s; *p; p++) {
    if (*p == '(') i++;
    if (*p == ')') { 
      i--;
      if (i == 0) test = 1;
    }
    if (i < 0) return i; 
    if (test && *p == '(')  return -999;
  }
  return i;
}
