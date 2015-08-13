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
