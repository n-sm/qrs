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
cosos::~cosos() {};

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
  int hay_trio(int fil, int col);
  void hacer_jugada();
  int revisar_tablero();
  int hay_tres_iguales(int fil, int col);
  tablero();
} tab;

void tablero::mostrar_cosos()
{
  int i, j;
  cout << "   0 1 2 3 4 5 6 7" << endl;
  for(i = 0; i < NFILAS; ++i){
    cout << endl << i << "  ";
    for(j = 0; j < NCOLUMNAS; ++j){
      cout << coso[i][j].get_color() << " ";
    }
  }
  cout << endl << endl << "   0 1 2 3 4 5 6 7" << endl;
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
  //  lugar[fil][col].vaciar();
  cout << "elim: " << color << endl;	
  if(fil>0){
    if(color == lugar[fil-1][col].get_color()) eliminar(fil-1, col);
  };
  if(fil<NFILAS-1){
    if(color == lugar[fil+1][col].get_color()) eliminar(fil+1, col);
  };
  if(col>0){
    if(color == lugar[fil][col-1].get_color())  eliminar(fil, col-1);
  };
  if(col<NCOLUMNAS-1){
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
	if(fil == 0) coso[fil][col].set_color((rand() % 4)+1);
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

int tablero::hay_trio(int fil, int col){
	if(fil + 2 < NFILAS) {
		if(coso[fil][col].get_color()==coso[fil+1][col].get_color() &&
			coso[fil][col].get_color()==coso[fil+2][col].get_color())
			return 1;
	}
	if(fil + 1 < NFILAS && fil > 0) {
		if(coso[fil][col].get_color()==coso[fil+1][col].get_color() &&
			coso[fil][col].get_color()==coso[fil-1][col].get_color())
			return 1;
	}
	if(fil > 1) {
		if(coso[fil][col].get_color()==coso[fil-1][col].get_color() &&
			coso[fil][col].get_color()==coso[fil-2][col].get_color())
			return 1;
	}
	if(col + 2 < NCOLUMNAS) {
		if(coso[fil][col].get_color()==coso[fil][col+1].get_color() &&
			coso[fil][col].get_color()==coso[fil][col+2].get_color())
		return 1;
	}
	if(col + 1 < NCOLUMNAS && col > 0) {
		if(coso[fil][col].get_color()==coso[fil][col+1].get_color() &&
			coso[fil][col].get_color()==coso[fil][col-1].get_color())
		return 1;
	}
	if(col > 1) {
		if(coso[fil][col].get_color()==coso[fil][col-1].get_color() &&
			coso[fil][col].get_color()==coso[fil][col-2].get_color())
		return 1;
	}
	return 0;
}

int tablero::hay_tres_iguales(int fil, int col){
  //  int retu;
  if(hay_trio(fil, col)) return 1;
  if(fil > 0){
    if(coso[fil][col].get_color()==coso[fil-1][col].get_color()){
      if(hay_trio(fil-1,col)) return 1;
    }
  }
  if(fil < NFILAS-1){
    if(coso[fil][col].get_color()==coso[fil+1][col].get_color()){
      if(hay_trio(fil+1, col)) return 1;
    }
  }
  if(col > 0){
    if(coso[fil][col].get_color()==coso[fil][col-1].get_color()){
      if(hay_trio(fil, col-1)) return 1;
    }
  }
  if(col < NCOLUMNAS-1){
    if(coso[fil][col].get_color()==coso[fil+1][col].get_color()){
      if(hay_trio(fil,col+1)) return 1;
    }
  }
  return 0;
};

void tablero::hacer_jugada(){

	int fila, columna;
	cout << "Ingrese FILA y COLUMNA" << endl ;
	cin >> fila >> columna;
	if(fila == 9 || columna == 9) exit(1);
	if(!hay_tres_iguales(fila, columna)){
		cout << "                                                      No hay trio!!!! " << endl;
	}
	else {
		eliminar(fila, columna);
		cout << "                                                      Hay trio" << endl;
	}
	rellenar();
	mostrar_cosos();
	
}
int tablero::revisar_tablero(){
	int i, j, retu = 0;
	for(i = NCOLUMNAS - 1; i > -1; --i){
		for(j = NFILAS - 1; j > -1; --j){
			if(hay_tres_iguales(j, i)) retu = 1;
		}
	}
	if(!retu) cout << "No hay mas ternas" ;
	return retu;
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
    while(tab.revisar_tablero()){
	  tab.hacer_jugada();
  }
  cout << endl;
  
  
  

  
	return 0;
};
