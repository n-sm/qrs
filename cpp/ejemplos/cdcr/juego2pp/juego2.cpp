#include <stdlib.h>     /* srand, rand */
#include <iostream>
#define NFILAS 7
#define NCOLUMNAS 8

#include "Coso.cpp"
#include "Punto.cpp"
#include "Tablero.cpp"

using namespace std;

int main()
{
   Tablero elTablero; 

   elTablero.dibujarTablero();
   while(elTablero.revisar_Tablero()){
     elTablero.HacerJugada();
     elTablero.dibujarTablero();
   };

     cout << endl;
    /*
    while(elTablero.coordenadasValidas()){
      elTablero.pedirCoordenadas();
    }
    */
    return 0;

}

#include <iostream>

class Coso {
  int color;
 public :
  void set_color(int num);
  int get_color();
  Coso();
  ~Coso();
};

#include <stdlib.h>     /* srand, rand */
#include "Coso.h"
//#include <iostream>


void Coso::set_color(int num) {color = num + 1;};

int Coso::get_color() { return color; };

Coso::Coso() { set_color(rand() % 4); };

Coso::~Coso() {};

#include <iostream>

class Punto {
 public :
  int coordenadas[2];
  void set_coordenadas(int fil, int col);
  int* get_coordenadas();
  Punto();
  ~Punto();
};
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

#include <iostream>

class Tablero {
  Coso coso[NFILAS][NCOLUMNAS];
  int contar;
  Punto partida, llegada;
public :
  void dibujarTablero();
  void mostrar_coso(int fila, int columna);
  int eliminar(int fila, int columna);
  //  void ligar_Coso(int fil, int col);
  void ocupar_lugar(int fil, int col);
  void drop(int col, int fil_desde, int fil_hasta);
  void rellenar();
  int hay_trio(int fil, int col);
  void set_partida(int fila, int columna);
  void set_llegada(int fila, int columna);
  void pedirCoordenadas();
  void chequearCoordenadas(int input[4]);
  int coordenadasValidas();
  void HacerJugada();
  void hacer_jugada();
  int revisar_Tablero();
  void set_punto(int fila, int columna);

  Tablero();
} ;
#include "Tablero.h"
#include <iostream>
using namespace std;

void Tablero::dibujarTablero()
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
};

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
};

void Tablero:: drop(int col, int fil_desde, int fil_hasta){
  coso[fil_hasta][col] = coso[fil_desde][col];
  coso[fil_desde][col].set_color(-1);
};

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
};

void Tablero::rellenar(){
  int i, j, k;
  for(i = NFILAS-1; i >= 0; --i){
    for(j = NCOLUMNAS-1; j >= 0; --j){
      if(coso[i][j].get_color() < 1){
	ocupar_lugar(i,j);
      }
    }
  }
};

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
};

void Tablero::set_partida(int fila, int columna){
  partida.set_coordenadas(fila, columna);
};

void Tablero::set_llegada(int fila, int columna){
  llegada.set_coordenadas(fila, columna);
};

void Tablero::chequearCoordenadas(int input[4]){
  int i, j, k  = 0;
  for(i = 0; i < 4; ++i)
    if(input[k]==9) ++k;
  if(k > 0) exit(1);
  j = 0;
  for(i = 0; i < 4; ++i)
    if(input[i] < 0) ++j;
  for(i = 0; i < 3; i += 2) 
    if(input[i] >= NFILAS) ++j;
  for(i = 1; i < 4; i += 2)
    if(input[i] >= NCOLUMNAS) ++j;
  if(j > 0){
    cout << "\nAl menos una de las coordenadas ingresadas exceden el rango.\n Intente de nuevo.\n ";
    pedirCoordenadas();
  }
};

void Tablero::pedirCoordenadas(){
  int input[4];
  cout << "Ingrese FILA y COLUMNA de cada punto (algun 9 para salir): ";
  cin >> input[0] >> input[1] >> input[2] >> input[3];
  chequearCoordenadas(input);  
  set_partida(input[0], input[1]);
  set_llegada(input[2], input[3]);
};

int Tablero::coordenadasValidas(){
  int fil = 0, col = 1;
  int *part, *lleg;
  part = partida.get_coordenadas();
  lleg = llegada.get_coordenadas();
  return  (part[fil]==lleg[fil]&&part[col]+2==lleg[col])||(part[col]==lleg[col]&&part[fil]+2==lleg[fil]);
};

void Tablero::HacerJugada(){
  int mismaCol, mismaFil, mismoColor = 0, fil = 0, col = 1,  i;
  int *part, *lleg;
  pedirCoordenadas();
  while(!coordenadasValidas()){
    cout << "Las coodenadas fueron incorrectas.\n"
	 << "Se debe denotar un segmento de una fila o de una columna\n"
	 << "que tenga tres cosos de longitud.\n" << "De nuevo: " ;
    pedirCoordenadas();
  }
  part = partida.get_coordenadas();
  lleg = llegada.get_coordenadas();
  mismaCol = (part[fil]==lleg[fil]-2 && part[col]==lleg[col]); // misma columna
  mismaFil = (part[fil]==lleg[fil] && part[col]==lleg[col]-2); // misma fila
  if(mismaCol){
    if(coso[part[fil]][part[col]].get_color() == coso[lleg[fil]][lleg[col]].get_color()){
    mismoColor = coso[part[fil]][part[col]].get_color() == coso[part[fil]+1][part[col]].get_color();
    }
  }
  if(mismaFil){
    if(coso[part[fil]][part[col]].get_color() == coso[lleg[fil]][lleg[col]].get_color()){
    mismoColor = coso[part[fil]][part[col]].get_color() == coso[part[fil]][part[col]+1].get_color();
    }
  }

  if(mismaCol){ 
    if(mismoColor){
      for(i = part[0]; i <= lleg[0] ; ++i){
       	coso[i][lleg[1]].set_color(-1);
	cout << "                                             " 
	     << "Se elimina: " <<  i  << " " << lleg[1] << endl;
      }
    }
  }
  else if(mismaFil){ 
    if(mismoColor){ 
      //  cout << "\n se eliminan los cosos indicados.\n";
      for(i = part[1];i <= lleg[1]; ++i){
	coso[part[0]][i].set_color(-1); 
	cout << "                                            "
	     << "Se elimina: " <<  part[0]  << " " << i << endl;
      }
    }
  }
  rellenar();
};

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
  dibujarTablero();
};

int Tablero::revisar_Tablero(){
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
};
