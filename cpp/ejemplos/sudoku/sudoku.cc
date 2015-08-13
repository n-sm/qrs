// este programa esta mal. Supone que se puede llenar en casos donde ya no es posible hacerlo
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#define LADO 3
#define CAJAS 9
#define SE_VEN 3
class Celda {
	int numero;
	int estado;
public :
	void set_numero(int arg);
	int get_numero();
	void set_estado(int arg);
	int get_estado();
	
	Celda();
	~Celda();
	
};

void Celda::set_numero(int arg){	numero = arg;};
int Celda::get_numero(){ return numero;};
void Celda::set_estado(int arg){ estado = arg;};
int Celda::get_estado(){ return estado;};
Celda::Celda(){};
Celda::~Celda(){};
	
class Tablero {
	Celda celdas[CAJAS][LADO][LADO];
	Celda *ptrtab[2][9][9];
public:
	void dibujarCaja(int caja);
	void dibujar3Cajas(int desde, int hasta);
	void dibujarTablero();
	void mostrar3Cajas(int desde, int hasta);
	void mostrarTablero();
	int Tablero::get_numeroT(int caja, int fila, int columna); //esto andaba sin Tablero::
	void Tablero::set_estadosT();
	void Tablero::set_filPointers(int desde, int hasta);
	void Tablero::set_colPointers(int desde, int hasta);
	void Tablero::set_pointers();
	int Tablero::get_pointer(int filCol, int nro, int cel);
	void mostrar_pointers();
	Tablero();
	~Tablero();
};
Tablero::Tablero(){
	int i, j, k;
	set_pointers();
	for(i = 0; i < CAJAS ; ++i){
		for(j = 0; j < LADO; ++j){
			for(k = 0; k < LADO; ++k){
				celdas[i][j][k].set_numero((rand() % 9) + 1);
			}
		}
	}
};
/*
i es el nro de cuadros, j de filas, k de columnas.
*/
Tablero::~Tablero(){};

void Tablero::dibujarCaja(int caja){
int j, k;
for(j = 0; j < LADO; ++j){
	std::cout << "  \n";
	for(k = 0; k < LADO; ++k){
		std::cout << celdas[caja][j][k].get_numero();
	}
}
};
void Tablero::dibujar3Cajas(int desde, int hasta){
int i, j, k;
	for(j = 0; j < LADO ; ++j){
		std::cout << "\nFila " << j << " ";
		for(i = desde; i < hasta + 1; ++i){
			std::cout << "  ";
			for(k = 0; k < LADO; ++k){
				std::cout << celdas[i][j][k].get_numero();
			}
		}
	}
};
void Tablero::dibujarTablero(){

	dibujar3Cajas(0, 2);
	std::cout << "\n";
	dibujar3Cajas(3, 5);
	std::cout << "\n";
	dibujar3Cajas(6, 8);
	std::cout << "\n";

};
int Tablero::get_numeroT(int caja, int fila, int columna){
	return celdas[caja][fila][columna].get_numero();
};
void Tablero::mostrar3Cajas(int desde, int hasta){	
	int i, j, k;
	for(j = 0; j < LADO ; ++j){
		std::cout << "\nFila " << j << " ";
		for(i = desde; i < hasta + 1; ++i){
			std::cout << "  ";
			for(k = 0; k < LADO; ++k){
				if(celdas[i][j][k].get_estado() == 1){
					std::cout << celdas[i][j][k].get_numero();
				}
				else std::cout << " ";
			}
		}
	}
};
void Tablero::mostrarTablero(){
	mostrar3Cajas(0, 2);
	std::cout << "\n";
	mostrar3Cajas(3, 5);
	std::cout << "\n";
	mostrar3Cajas(6, 8);
	std::cout << "\n";
};
void Tablero::set_estadosT(){
	int i, j, k;
	for(i = 0; i < CAJAS; ++i){
		for(j = 0; j < LADO; ++j){
			for(k = 0; k < LADO; ++k){
				if((rand() % CAJAS) < SE_VEN) celdas[i][j][k].set_estado(1);
				else celdas[i][j][k].set_estado(0);
			}
		}
	}

};
void Tablero::set_filPointers(int desde, int hasta){
  // Hay que tener cuidado con los args.
  // Pueden ser: (0,2), (3,5) y (6,8). 
  // Nada más.
  int i, j, k, l;
  for(j = 0; j < LADO ; ++j){
    l = 0;
    for(i = desde; i < hasta + 1; ++i){
      for(k = 0; k < LADO; ++k){
		ptrtab[0][j+desde][l++] = &celdas[i][j][k];
      }
    }
  }
};
void Tablero::set_colPointers(int desde, int hasta){
  // Hay que tener cuidado con los args.
  // Pueden ser: (0,7), (1,8) y (2,9). 
  // Nada más.

  int i, j, k, l;
  for(k = 0; k < LADO ; ++k){
    l = 0;
    for(i = desde; i < hasta; i += 3){
      for(j = 0; j < LADO; ++j){
	ptrtab[1][k+desde*3][l++] = &celdas[i][j][k];
      }
    }
  }
};
void Tablero::set_pointers(){
	int i;
	for(i = 0; i < 7; i += 3)	set_filPointers(i, i+2);
	for(i = 0; i < 3; ++i) set_colPointers(i, i+7);
};
int Tablero::get_pointer(int filCol, int nro, int cel){
	return ptrtab[filCol][nro][cel]->get_numero();
};
void Tablero::mostrar_pointers(){
	int i, j, k;
	for(i = 0; i < 2; ++i){
		std::cout << "FIL/COL: " << i << "\n";
		for(j = 0; j < 9; ++j){
			std::cout << "\n   nro: "  << j << " ";
			for(k = 0; k < 9; ++k)
				std::cout << get_pointer(i,j,k);
		}
	}
};

int main()
{
	int i, j, k;
	Tablero elTablero;
	elTablero.dibujarTablero();
	elTablero.set_estadosT();
	elTablero.mostrarTablero();
	std::cout << "\n get: ";
	elTablero.mostrar_pointers();
	//std::cout << elTablero.get_pointer(0,1,2);
	//elTablero.mostrar_pointers();


	return 0;
}
