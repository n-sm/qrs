#include <iostream>
#include <string>

  struct casillero;

void f1(const char* p);
void printcas(casillero* p);

struct casillero {
  int caja;
  int fcaja;
  int ccaja;
  int fila;
  int columna;
};

int main(){
  casillero primero = { 30, 40, 240, 10, 6  };
  int i = 11;
  const char* ptr;
  ptr = "texto";

  f1(ptr);
 
}

void f1(const char* p){ 
 
 std::cout << "\nEsta funcion devuelve un caracter por"
   "linea, son los caraceters apuntados por un pointer.\n";
 int i;
 for(i = 0; i < 111 ; ++i)
   std::cout << p[i] << "\n";
	 
    };

void printcas(casillero* p)
{
  std::cout << p-> caja << "\n"
	    << p-> fcaja << "\n";
};
