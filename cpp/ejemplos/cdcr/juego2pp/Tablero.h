#include <iostream>
#include "Coso.h"
#include "Punto.h"
#include <stdlib.h>     /* srand, rand */
#define  NFILAS 7
#define  NCOLUMNAS 8

class Tablero {
  Coso coso[NFILAS][NCOLUMNAS];
  int contar;
  Punto partida, llegada;
public :
  void dibujarTablero();
  void mostrar_coso(int f, int c){ std::cout << "\n" << coso[f][c].get_color() << "\n";};
  int eliminar(int fila, int columna);
  void ocupar_lugar(int fil, int col);
  void drop(int col, int fil_desde, int fil_hasta);
  void rellenar();
  int hay_trio(int fil, int col);
  void set_partida(int fila, int columna){partida.set_coordenadas(fila, columna);};
  void set_llegada(int fila, int columna){llegada.set_coordenadas(fila, columna);};
  void pedirCoordenadas();
  void chequearCoordenadas(int input[4]);
  int coordenadasValidas();
  void HacerJugada();
  void hacer_jugada();
  int revisar_Tablero();
  void set_punto(int fila, int columna);
  int mismo_color(Coso a, Coso b, Coso c){
    return a.get_color() == b.get_color() && a.get_color() == c.get_color();};
  int mismo_color(Coso a, Coso b){ return a.get_color() == b.get_color();};
  int mismo_color(int i, Coso b){  return i == b.get_color();};
  Tablero() {};
} ;
