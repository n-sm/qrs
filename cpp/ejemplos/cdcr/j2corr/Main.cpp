//#include "stdafx.h"
#include <stdlib.h>     /* srand, rand */
#include <iostream>
/*
#define NFILAS 7
#define NCOLUMNAS 8
#include "Cosos.h"
#include "Punto.h"
#include "Tablero.h"
*/
#include "Cosos.cpp"
#include "Punto.cpp"
#include "Tablero.cpp"

using namespace std; //System
int main()
{
   Tablero elTablero; 
   elTablero.dibujar_Tablero();
    while(elTablero.revisar_tablero()){
        elTablero.hacer_jugada();
    }

    cout << endl;
    return 0;

}
