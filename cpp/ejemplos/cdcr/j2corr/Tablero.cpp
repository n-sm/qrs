#include "Tablero.h"
#include <iostream>


using namespace std;

void Tablero::dibujar_Tablero()
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

void Tablero::mostrar_coso(int fila, int columna){
	cout << endl << coso[fila][columna].get_color() << endl;
}

int Tablero::eliminar(int fil, int col){
  int color;
  color = coso[fil][col].get_color();
  coso[fil][col].set_color(-1);
  contar++;
  if(fil>0){
    if(color == coso[fil-1][col].get_color()) eliminar(fil-1, col);
  };
  if(fil<NFILAS-1){
    if(color == coso[fil+1][col].get_color()) eliminar(fil+1, col);
  };
  if(col>0){
    if(color == coso[fil][col-1].get_color())  eliminar(fil, col-1);
  };
  if(col<NCOLUMNAS-1){
    if(color == coso[fil][col+1].get_color())  eliminar(fil, col+1);
  };
  return contar;
}

void Tablero:: drop(int col, int fil_desde, int fil_hasta){
  coso[fil_hasta][col] = coso[fil_desde][col];
  coso[fil_desde][col].set_color(-1);
}

void Tablero::rellenar(){
  int i, j, k;

  for(i = NFILAS-1; i >= 0; --i){
    for(j = NCOLUMNAS-1; j >= 0; --j){

      if(coso[i][j].get_color() < 1){
          ocupar_lugar(i,j);
      }
    }
  }
}

void Tablero::ocupar_lugar(int fil, int col){
  int i, j, k;
  if(coso[fil][col].get_color() < 1){
	if(fil == 0) coso[fil][col].set_color((rand() % 4)+1);
	else{
	  k = fil-1;
	  if(coso[k][col].get_color() > 0){
	    drop(col, k, fil);
	  }
	  else {
	    ocupar_lugar(k, col);
	    ocupar_lugar(fil,col);
	  }
	}
  }
}	    

int Tablero::hay_trio(int fil, int col){
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

void Tablero::hacer_jugada(){
  int fila, columna, mensage, color;
  contar = 0;
  cout << "Ingrese FILA y COLUMNA" << endl ;
  cin >> fila >> columna;
  color = coso[fila][columna].get_color();
  if(fila == 9 || columna == 9) exit(1);
  if(!hay_trio(fila, columna)){
    cout << endl << "                                                      No!!!! " << endl;
  }
  else {
    mensage = eliminar(fila, columna);
    cout << "                                                   Si....     se eliminaron " << mensage;
    cout << " de color " << color << endl;
  }
  rellenar();
  dibujar_Tablero();
}

int Tablero::revisar_tablero(){
	int i, j, retu = 0;
	for(i = NCOLUMNAS - 1; i > -1; --i){
		for(j = NFILAS - 1; j > -1; --j){
			if(hay_trio(j, i)) retu = 1;
		}
	}
	if(!retu) cout << "No hay mas ternas" ;
	return retu;
}
Tablero::Tablero() {
}
