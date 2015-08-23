//#include "stdafx.h"
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#define NFILAS 7
#define NCOLUMNAS 8

using namespace std; //System

class cosos {
	int color;
public :
	void set_color(int num);
	int get_color();
	cosos();
	~cosos();
};
void cosos::set_color(int num) {color = num + 1;};
int cosos::get_color() { return color; };

cosos::cosos() {
	set_color(rand() % 4);
};
cosos::~cosos() {
	cout << " ELIM " ;
};

class lugares {
	cosos *lugar;
	int estado;// 0 si VACÍO
public :
	cosos *lindante[4];
	void asignar_su_coso(cosos *su_coso);
	void asignar_lindantes(cosos *arriba, cosos *abajo, cosos *derecha, cosos *izquierda);
	int get_color_lindantes(int entero);
	int get_color(); 
	void set_color(int num); 
	void vaciar();
	
};
void lugares::asignar_lindantes(cosos *arriba, cosos *abajo, cosos *izq, cosos *dcha){
	lindante[0] = arriba;
	lindante[1] = abajo;
	lindante[2] = izq;
	lindante[3] = dcha;
}
void lugares::asignar_su_coso(cosos *su_coso){
	lugar = su_coso;
	estado = 1;
}
int lugares::get_color(){
	int retu;
	retu = lugar->get_color();
	return retu;
}
void lugares::set_color(int num){
  lugar->set_color(num);
}

int lugares::get_color_lindantes(int entero){
	int retu;
	retu = lindante[entero]->get_color();
	return retu;
}
void lugares::vaciar(){
	estado = 0;
}


class tablero {
  cosos coso[NFILAS][NCOLUMNAS];
  lugares lugar[NFILAS][NCOLUMNAS];
public :
  void mostrar_cosos();
  void mostrar_lugares();
  void mostrar_coso(int fila, int columna);
  void eliminar(int fila, int columna);
  void ligar_cosos(int fil, int col);
  void mostrar_lindante(int fila, int columna, int entero);
  void drop(int col, int fil_desde, int fil_hasta);
  void rellenar();
  void ocupar_lugar(int fil, int col);
  tablero();
} tab;

void tablero::mostrar_cosos()
{
  int i, j;
  for(i = 0; i < NFILAS; ++i){
    cout << endl << i << "  ";
    for(j = 0; j < NCOLUMNAS; ++j){
      cout << coso[i][j].get_color();
    }
  }
  cout << endl;
};
void tablero::mostrar_lugares()
{
  int i, j;
  for(i = 0; i < NFILAS; ++i){
    cout << endl << i << "  ";
    for(j = 0; j < NCOLUMNAS; ++j){
      cout << lugar[i][j].get_color();
    }
  }
  cout << endl;
};
void tablero::mostrar_coso(int fila, int columna){
	cout << endl << coso[fila][columna].get_color() << endl;
};
void tablero::mostrar_lindante(int fila, int columna, int entero){
	cout << "  " << lugar[fila][columna].get_color_lindantes(entero);
};
void tablero::eliminar(int fil, int col){
  int i, color;
  color = lugar[fil][col].get_color();
  lugar[fil][col].set_color(-1);
  lugar[fil][col].vaciar();
  cout << color ;	
  if(fil>0){
    if(color == lugar[fil-1][col].get_color()) eliminar(fil-1, col);
  };
  if(fil<NFILAS){
    if(color == lugar[fil+1][col].get_color()) eliminar(fil+1, col);
  };
  if(col>0){
    if(color == lugar[fil][col-1].get_color())  eliminar(fil, col-1);
  };
  if(col<NCOLUMNAS){
    if(color == lugar[fil][col+1].get_color())  eliminar(fil, col+1);
  };
};

void tablero::ligar_cosos(int fil, int col){
	lugar[fil][col].asignar_lindantes(&coso[fil-1][col], &coso[fil+1][col], &coso[fil][col-1], &coso[fil][col+1]);
}
void tablero:: drop(int col, int fil_desde, int fil_hasta){
  coso[fil_hasta][col] = coso[fil_desde][col];
  coso[fil_desde][col].set_color(-1);
}
void tablero::rellenar(){
  int i, j, k;

  for(i = NFILAS-1; i >= 0; --i){
    for(j = NCOLUMNAS-1; j >= 0; --j){

      if(coso[i][j].get_color() < 1){

	ocupar_lugar(i,j);
      }
    }
  }
};
void tablero::ocupar_lugar(int fil, int col){
  int i, j, k;
  if(coso[fil][col].get_color() < 1){
	if(fil == 0) coso[fil][col].set_color(6);
	else{
	  k = fil-1;
	  if(coso[k][col].get_color() > 0){
	   
	    drop(col, k, fil);
	    // mostrar_lugares();
	  }
	  else {
	    ocupar_lugar(k, col);
	    ocupar_lugar(fil,col);
	  }
	  //aca hay q hacer algo
	  
	}
  }
}	    
tablero::tablero() {
	int i, j;
	for(i = 0; i < NFILAS; ++i){
		for(j = 0; j < NCOLUMNAS; ++j){
			lugar[i][j].asignar_su_coso(&coso[i][j]);
		}
	}
	for(i = 0; i < NFILAS; ++i){
		for(j = 0; j < NCOLUMNAS; ++j){
			ligar_cosos(i, j);
		}
	}
};

int main()
{
  tab.mostrar_cosos();//muestra tab
  tab.mostrar_coso(0,0);//muestra uno
  cout << endl;
  tab.mostrar_lindante(4,4,0);
  tab.mostrar_lindante(1,1,1);
  tab.mostrar_lindante(1,1,2);
  tab.mostrar_lindante(1,1,3);
  tab.mostrar_coso(0,1);

  tab.eliminar(3,4);
  tab.drop(1, 0, 1);

  tab.mostrar_lugares();
  cout << endl;
  tab.mostrar_coso(0,0);
  cout << endl;
  tab.rellenar();
  tab.mostrar_lugares();
	
	return 0;
};

