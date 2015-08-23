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
  int mismo_color(Coso a, Coso b, Coso c);
  int mismo_color(Coso a, Coso b);
  int mismo_color(int i, Coso b);
  Tablero();
} ;
