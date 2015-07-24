#include <stdio.h>
#include <stdlib.h>
#define NAT_MAX 255
#define CERO 0

typedef unsigned int nat;
nat nats[NAT_MAX];
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

void prCar(nodo elnodo) { printf("data: %d\n", *(elnodo.data.key.i));}
void prlist(nodo elnodo) 
{
  prCar(elnodo);
  if (elnodo.next != NULL) prlist(*(elnodo.next));
  else printf("||\n");
}


/*
nodo* cons(nodo* head, nodo* tail)
{
  nodo* out;
  out = nuevo();
  out.data.ptr = head;
  out.next = tail;
  return out;
}
*/
/*
nodo unnodo() 
{

}
*/
nodo* nuevo() {
  nodo *out;
  out = malloc(sizeof(nodo));
  return out;
}


int main() 
{

  int i;
  for (i=CERO; i <= NAT_MAX; i++)
    nats[i] = i+1;

  nodo n1, n2, n3, n4;
  n1.data.key.i = nats;
  n2.data.key.i = nats + 1;
  n3.data.key.i = nats + 2;

  n1.next = &n2;
  n2.next = &n3;
  n3.next = NULL;

  n4.data.ptr = &n1;
  n4.next = NULL;
  prCar(n1);
  prlist(n1);
  printf("=======\n");
  prlist(n4);
  
}
