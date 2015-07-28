#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

typedef struct nodo nodo;

struct nodo {
  unsigned int count;
  union { 
    nodo* ptr;
    union {
      int* i;
      double* d;
      char* c;
    } key;
  } data;
  nodo* next;
};

nodo* nuevo()
{
  nodo *tmp = malloc(sizeof(nodo));
  if(!tmp) {
    printf("Error de memoria\n");
    return NULL;
  }
  return tmp;
}

void str2nodo(char* str, nodo *nod)
{
  nod->next=NULL;
  nod->data.key.c = str;
}

void printnodo(nodo* arg)
{
  printf("%s\n", arg->data.key.c);
}

void str2strgs(char* str, nodo *nod)
{
  int i;
  char *p = str;
  for(i=0; *p != '\0', *p != ' ' ; i++, p++)
    ;
  
  printf("primer espacio o null: %d\n", i);
}

int checkParen(char* s)
{
  char *p=s;
  if (*p == '\0') return 1; // mmmm '\0' es lista vacia??
  do {
    if (*p != '(' && *p != ' ') return 0;
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
    if (i < 0) return 0; 
    if (test && *p == '(')  return 0;
  }
  if (i == 0) return 1;
  else return 0;
}

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

char* loop()
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

int main(int arc, char *argv[])
{
  char *line;
  do {
  printf(".\\ ");
  line = loop();
  printf("ret de wrongParen: %d\n",  wrongParen(line));
  free (line);
  } while (1);

  /*
  nodo *unnodo = nuevo();
  nodo arr[5];
  char *str = "Cstring";
  int i;
  for(i=0; i<5; i++)
    str2nodo(str, &arr[i]);
  str = "otraCString";
  str2nodo(str, unnodo);
  printnodo(unnodo);
  for(i=0; i<5;i++)
    printnodo(&arr[i]);
  char str2[11] = "otra string";
  for(i=0; str2[i] != '\0'; i++)
    printf("char: %c, i:%d",str2[i], i);
  printf("str2[0]: %c", str2[0]);
  printf("\n");
  free(unnodo);

  */
  return 0;
}
