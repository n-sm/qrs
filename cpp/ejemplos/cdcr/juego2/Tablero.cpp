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

int Tablero::eliminar(int f, int c){
  int color;
  color = coso[f][c].get_color();
  coso[f][c].set_color(-1);
  contar++;
  if(f>0){
    if(mismo_color(color,coso[f-1][c])) eliminar(f-1, c);
  };
  if(f<NFILAS-1){
    if(mismo_color(color,coso[f+1][c])) eliminar(f+1, c);
  };
  if(c>0){
    if(mismo_color(color,coso[f][c-1])) eliminar(f, c-1);
  };
  if(c<NCOLUMNAS-1){
    if(mismo_color(color,coso[f][c+1])) eliminar(f, c+1);
  };
  return contar;
};

void Tablero:: drop(int col, int fil_desde, int fil_hasta){
  coso[fil_hasta][col] = coso[fil_desde][col];
  coso[fil_desde][col].set_color(-1);
};

void Tablero::ocupar_lugar(int f, int c){
  int i, j;
  if(coso[f][c].get_color() < 1){
	if(f == 0) coso[f][c].set_color((rand() % 4)+1);
	else{
	  if(coso[f-1][c].get_color() > 0){
	    drop(c, f-1, f);
	  }
	  else {
	    ocupar_lugar(f-1, c);
	    ocupar_lugar(f,c);
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

int Tablero::hay_trio(int f, int c){
  if(f + 2 < NFILAS) {
    if(mismo_color(coso[f][c], coso[f+1][c], coso[f+2][c])) return 1;
  }
  if(f + 1 < NFILAS && f > 0) {
    if(mismo_color(coso[f][c], coso[f+1][c], coso[f-1][c])) return 1;
  }
  if(f > 1) {
    if(mismo_color(coso[f][c], coso[f-1][c], coso[f-2][c])) return 1;
  }
  if(c + 2 < NCOLUMNAS) {
    if(mismo_color(coso[f][c], coso[f][c+1], coso[f][c+2])) return 1;
  }
  if(c + 1 < NCOLUMNAS && c > 0) {
    if(mismo_color(coso[f][c], coso[f][c+1], coso[f][c-1])) return 1;
  }
  if(c > 1) {
    if(mismo_color(coso[f][c], coso[f][c-1], coso[f][c-2])) return 1;
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
  int mismaCol, mismaFil, mismoColor = 0, f = 0, c = 1,  i;
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
  mismaCol = (part[f]==lleg[f]-2 && part[c]==lleg[c]); // misma columna
  mismaFil = (part[f]==lleg[f] && part[c]==lleg[c]-2); // misma fila
  if(mismaCol){
    if(mismo_color(coso[part[f]][part[c]], coso[lleg[f]][lleg[c]])){
      mismoColor = mismo_color(coso[part[f]][part[c]], coso[part[f]+1][part[c]]);
    }
  }
  if(mismaFil){
    if(mismo_color(coso[part[f]][part[c]], coso[lleg[f]][lleg[c]])){
      mismoColor = mismo_color(coso[part[f]][part[c]], coso[part[f]][part[c]+1]);
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

int Tablero::mismo_color(Coso a, Coso b, Coso c){
  return a.get_color() == b.get_color() &&
    a.get_color() == c.get_color();
}
int Tablero::mismo_color(Coso a, Coso b){
  return a.get_color() == b.get_color();
}
int Tablero::mismo_color(int i, Coso b){
  return i == b.get_color();
}


Tablero::Tablero() {
};
