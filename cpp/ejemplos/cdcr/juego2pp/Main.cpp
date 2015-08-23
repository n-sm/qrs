#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include "Tablero.h"
/*
#include "Coso.h"
#include "Punto.h"
#include "Tablero.h"
*/

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
