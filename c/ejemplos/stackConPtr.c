/* Una pila en C */
#include <stdio.h>

#define VACIA (top == pila ? 1 : 0)
#define LLENA (top == (pila + 24) ? 1 : 0)

unsigned char pila[25];
unsigned char* top = pila;

void push(char letra)
{
  if (LLENA) printf("stack overflow\n");
  else *(++top) = letra;
}

char pop()
{
  if (VACIA) printf("underflow\n");
  else return *(top--);
}



int main()
{
 
  printf("vacia? %d\n", VACIA);
  printf("push('a');\n");
  push('a');
 
  printf("vacia? %d\n", VACIA);
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
