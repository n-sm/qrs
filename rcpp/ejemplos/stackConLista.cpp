/* Una pila en C implementada como 'linked list'*/
#include <Rcpp.h>

#define VACIA (top == NULL)

using namespace std;

typedef struct nodo nodo;

struct nodo {
  char data;
  nodo* next;
};


nodo* top = NULL; // Al inicio, la lista está vacía.

nodo* nuevo()
{
  nodo *tmp = new nodo;
  if(!tmp) {
    cout << "Error de memoria\n";
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
    cout << "underflow\n";
    return 0;
  }
  else {
    nodo* tmp = top;
    ret = top->data;
    top = top->next;
    delete tmp;
    return ret;
  }
}

// [[Rcpp::export]]
int main()
{
  int i;
  char c;
  cout << "HW\n";
  for(i=0, c='1'; i < 9; i++, c++)
    push(c);
  for(i=0; i < 9; i++)
    cout << pop();
  //  char ctmp;


}
