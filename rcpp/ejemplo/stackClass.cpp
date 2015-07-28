/* Esto es solo un ejemplo. eEn si no tiene utilidad.
   Para usarlo desde R escribir:
   sourceCpp('fact.cpp')
*/

#include <Rcpp.h>

#define SIZE 100
#define NUM 123

using namespace Rcpp;
using namespace std;

class stack {
  int stck[SIZE];
  int tos;
public:
  void init();
  void push(int i);
  int pop();
};

void stack::init() { tos = 0; }
void stack::push(int i)
{
  if(tos==SIZE) {
    cout << "overlow" << endl;
    return;
  }
  stck[tos++] = i;
}
int stack::pop()
{
  if (tos == 0) {
    cout << "underflow" << endl;
    return 0;
  }
  return stck[--tos];
}


// [[Rcpp::export]]
void main()
{
  cout << "una string" << endl;
  stack mystack;
  mystack.init();
  int i;
  for (i=0; i<NUM; i++)
    mystack.push(i);
  for (i=0; i<NUM; i++)
    cout << mystack.pop() << endl;
}
