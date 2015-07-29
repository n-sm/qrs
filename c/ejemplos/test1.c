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
void push2(char letra)
{
  nodo *tmp = nuevo();
  tmp->data = letra;
  tmp->next = top;
  top = tmp;
   if(top->next == NULL) printf("===============aca next  es null\n");
}

char pop()
{
  char ret = '\0';
  if (top == NULL) {
    printf("underflow\n");
    return;
  }
  else {
    /*
    if (top->next == NULL) printf("========= el next es null!! 1de3~~~~~\n");
    if (top->next == NULL) printf("========= el next es null!! 1de3~~~~\n");
    if (top->next == NULL) printf("========= el next es null!! 1de3~~\n");
    if (top->next == NULL) printf("=========top->next es null aca!!!2de2\n");
    if (!(top->next == NULL)) printf("=========PERO ME DA top->next NO NUL!!!\n");
    */
    nodo* tmp = top;
    ret = top->data;
    top = top->next;
    free(tmp);
    return ret;
  }
}

char pt()
{
  return 'v';
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
  push2('a');

  if(top->next == NULL) printf(" = = = = = top->next es null\n");

  printf("vacia? %d\n", VACIA); //no, tiene 'a'

  printf("\n\n");
  printf("pido pop\n");
  ctmp = pop();
  if(ctmp) printf("pop(): %c\n", ctmp); 
  else printf("/////////////////es null. No hubo \"pop\"\n");


  printf("vacia? %d  (TIENE Q DAR VACIA!!)\n", VACIA); //si, vacia


  printf("push2('b');\n");
  push2('b');
  printf("vacia? %d\n", VACIA);
  printf("pop(): %c\n", pop());
  printf("vacia? %d\n", VACIA);


  printf("pop(): %c\n", pop());
  printf("pop(): %c\n", pop());
  int i;
  char c;
  for (i=0, c='a'; i < 271; i++, c++) {
    printf("push2(%c);\n", c);
    push2(c);
  }
  for (i=0; i < 299; i++)
      printf("pop(): %c\n", pop());

}

