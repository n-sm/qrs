
#include "Definitions.h"
#include "Punto.h"
#include "Cosos.h"

class Tablero {
    Cosos coso[NFILAS][NCOLUMNAS];
    int contar;
    public :
    void    dibujar_Tablero();
    void    mostrar_coso(int fila, int columna);
    int     eliminar(int fila, int columna);
    void    ligar_cosos(int fil, int col);
    void    mostrar_lindante(int fila, int columna, int entero);
    void    drop(int col, int fil_desde, int fil_hasta);
    void    rellenar();
    int     hay_trio(int fil, int col);
    void    HacerJugada(Punto partida, Punto llegada);
    void    hacer_jugada();
    int     revisar_tablero();
    void    ocupar_lugar(int fil, int col);
        
    Tablero();
    };
