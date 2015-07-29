#include <stdio.h>
#include <stdlib.h>


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
