/* Una pila en C implementada como 'linked list'*/

#include <stdio.h>

#define VACIA (*top == NULL)

typedef struct nodo {
  char data;
  nodo* next;
} nodo;

static nodo* top = NULL; // Al inicio, la lista está vacía.

void push(char letra)
{
  nodo nuevo;
  nuevo.data = letra;
  nuevo.next = top;
  top = nuevo;
}
  
void push2(char letra)
{
  nodo nuevo = { letra , top };
  top = &nuevo;
}

char pop()
{
  if (VACIA) printf("underflow\n");
  else {
    char tmp = top->data;
    top = top->next;
    return tmp;
  }
}


int main()
{

  printf("vacia? %d\n", vacia());
  printf("push('a');\n");
  push('a');
  printf("vacia? %d\n", vacia());
  printf("pop(): %c\n", pop());
  printf("pop(): %c\n", pop());
  int i;
  for (i=0; i < 25; i++) {
    printf("push('a');\n");
    push('a');
  }
  for (i=0; i < 25; i++)
      printf("pop(): %c\n", pop());

             

}
