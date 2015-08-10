// Ejemplo de "C++ The Complete Reference" de Herb Schildt, p.273.

#define SIZE 100

class stack {
  int stck[SIZE];
  int tos;
public:
  void init();
  void push(int i);
  int pop();
};

stack mystack;

