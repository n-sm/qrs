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

void anodo(char* argch, nodo *argnod)
{
  argnod->next=NULL;
  argnod->data.key.c = argch;
}

void printnodo(nodo* arg)
{
  printf("%s\n", arg->data.key.c);
}



int main(int arc, char *argv[])
{
  nodo *unnodo = nuevo();
  printf("arc = %d\n",arc);


  if (arc < 2) return 0;
  //  printf("%s\n",argv[1]);
  anodo(argv[1], unnodo);
  printnodo(unnodo);
  free(unnodo);
  return 0;
}
