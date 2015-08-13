#include <iostream>

class Punto {
 public :
  int coordenadas[2];
  void set_coordenadas(int fil, int col);
  int* get_coordenadas();
  Punto();
  ~Punto();
};
