/* Una pila en C implementada como 'linked list'*/

#include <stdio.h>

#define VACIA (top == NULL)

typedef struct nodo nodo;

struct nodo {
  char data;
  nodo* next;
};


static nodo* top = NULL; // Al inicio, la lista está vacía.

  
void push2(char letra)
{
  nodo nuevo = { letra , top };
  top = &nuevo;
  //  if(top->next == NULL) printf("===============aca null es next\n");
}

char pop()
{
  //  char tmp = 'z';
  if (top == NULL) printf("underflow\n");
  else {
    if (top->next == NULL) printf("========= el next es null!! 1de2\n");
    if (top->next == NULL) printf("========= el next es null!! 1de2\n");
    if (top->next == NULL) printf("========= el next es null!! 1de2\n");

    if (top->next == NULL) printf("=========top->next es null aca!!!2de2\n");
    //top->data;
    //    top = top->next;
    return top->data;
  }
}


int main()
{
  printf("pop(): %c\n", pop()); // 

  printf("vacia? %d\n", VACIA); //si, vacia
  printf("push('a');\n"); 
  push2('a');
  printf("vacia? %d\n", VACIA); //no, tiene 'a'
  printf("pop(): %c\n", pop()); // saco 'a'
  printf("vacia? %d  (TIENE Q DAR VACIA!!)\n", VACIA); //si, vacia


  /*
  printf("push('b');\n");
  push2('b');
  printf("vacia? %d\n", VACIA);
  printf("pop(): %c\n", pop());
  printf("vacia? %d\n", VACIA);

  printf("sd");

  nodo* t = NULL;
  if (t == NULL) printf("t es NULL\n");
  nodo n1 = { 'a', t };
  if (n1.next == NULL) printf("n1.next es NULL\n");
  t = &n1;
  if (t->next == NULL) printf("t->next es NULL\n");
  t = t->next;  
  if (t == NULL) printf("t es NULL\n");

  
  /*
  printf("pop(): %c\n", pop());
  printf("pop(): %c\n", pop());
  int i;
  for (i=0; i < 25; i++) {
    printf("push('a');\n");
    push('a');
  }
  for (i=0; i < 25; i++)
      printf("pop(): %c\n", pop());
  */             
}


void push(char letra)
{
  nodo nuevo;
  nuevo.data = letra;
  nuevo.next = top;
  top = &nuevo;
}
