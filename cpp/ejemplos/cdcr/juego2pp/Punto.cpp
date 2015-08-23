#include "Punto.h"
//#include <iostream>

void Punto::set_coordenadas(int fil, int col){
  coordenadas[0] = fil;
  coordenadas[1] = col;
}

int* Punto::get_coordenadas(){
  int *ptr;
  ptr =  coordenadas;
  return ptr;
};

Punto::Punto(){};
Punto::~Punto(){};

