#include <stdio.h>
#include <stdlib.h>


typedef struct nodo nodo;

/*
  Data es un (void *). Puede referir a un int o a una c-string,
  o a otro nodo. Habra que usar casts y fijarse en type.
  type puede ser:
  list: apunta a otro nodo
  ent: apunta a un enter
  double: apunta a un double
  string: apunta a una cString
 */

struct nodo {
  unsigned short int count;
  unsigned short int type;
  void *data;
  nodo *next;
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
  //  nod->next=NULL;
  // nod->data.key.c = str;
}

void printnodo(nodo* arg)
{
  //  printf("%s\n", arg->data.key.c);
}

void str2strgs(char* str, nodo *nod)
{
  int i;
  char *p = str;
  for(i=0; *p != '\0', *p != ' ' ; i++, p++)
    ;
  printf("primer espacio o null: %d\n", i);
}


int main ()
{
  printf(":\n");
  int *ip;
  void *np;
  printf("sizeof ip: %lu\t", sizeof(ip));
  printf("sizeof np: %lu\n", sizeof(np));
  printf("sizeof nodo: %lu\t", sizeof(nodo));
  printf("sizeof int: %lu\t", sizeof(int));
  ip = malloc(sizeof(int));
  *ip = 45;
  np = (nodo *) ip;

  printf("sizeof np (que es un cast int): %lu\t", sizeof(np));
  printf("*ip es: %d\n", *ip);
  printf("*np es: %d\n", *((int *) np) );
  printf("sizeof void: %lu\t", sizeof(void));

}
