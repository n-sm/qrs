#include <stdio.h>


unsigned char pila[25];
unsigned int top = 0;

int vacia()
{
  if (top == 0) return 1;
  else return 0;
}

int llena()
{
  if (top == 24) return 1;
  else return 0;
}

void push(char letra)
{
  if (llena()) {
    printf("stack overflow\n");
    return;
  }
  else pila[++top] = letra;
}

char pop()
{
  if (vacia()) {
    printf("underflow\n");
  }
  else return pila[top--];
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
