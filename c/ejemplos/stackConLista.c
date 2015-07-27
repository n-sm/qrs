/* Una pila en C implementada como 'linked list'*/

#include <stdio.h>
#include <stdlib.h>

#define VACIA (top == NULL)

typedef struct nodo nodo;

struct nodo {
  char data;
  nodo* next;
};


nodo* top = NULL; // Al inicio, la lista está vacía.

nodo* nuevo()
{
  nodo *tmp = malloc(sizeof(nodo));
  if(!tmp) {
    printf("Error de memoria\n");
    return NULL;
  }
  return tmp;
}

void push(char letra)
{
  nodo *tmp = nuevo();
  tmp->data = letra;
  tmp->next = top;
  top = tmp;
}

char pop()
{
  char ret;
  if (top == NULL) {
    printf("underflow\n");
    return;
  }
  else {
    nodo* tmp = top;
    ret = top->data;
    top = top->next;
    free(tmp);
    return ret;
  }
}


int main()
{
  char ctmp;

  printf("vacia? %d\n", VACIA); //si, vacia

  printf("\n");
  printf("pido pop\n");
  ctmp = pop();
  if(ctmp) printf("pop(): %c\n", ctmp); 
  else printf("/////////////////es null. No hubo \"pop\"\n");


  printf("\n");
  printf("pido pop\n");
  ctmp = pop();
  if(ctmp) printf("pop(): %c\n", ctmp); 
  else printf("/////////////////es null. No hubo \"pop\"\n");


  printf("vacia? %d\n\n", VACIA); //si, vacia

  printf("push('a');\n"); 
  push('a');

  if(top->next == NULL) printf(" = = = = = top->next es null\n");

  printf("vacia? %d\n", VACIA); //no, tiene 'a'

  printf("\n\n");
  printf("pido pop\n");
  ctmp = pop();
  if(ctmp) printf("pop(): %c\n", ctmp); 
  else printf("/////////////////es null. No hubo \"pop\"\n");


  printf("vacia? %d  (TIENE Q DAR VACIA!!)\n", VACIA); //si, vacia


  printf("push('b');\n");
  push('b');
  printf("vacia? %d\n", VACIA);
  printf("pop(): %c\n", pop());
  printf("vacia? %d\n", VACIA);


  printf("pop(): %c\n", pop());
  printf("pop(): %c\n", pop());
  int i;
  char c;
  for (i=0, c='a'; i < 271; i++, c++) {
    printf("push(%c);\n", c);
    push(c);
  }
  for (i=0; i < 299; i++)
      printf("pop(): %c\n", pop());

}

