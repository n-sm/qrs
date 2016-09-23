#ifndef TALLER_INCLUDED_H
#define TALLER_INCLUDED_H

using namespace std;

//Ejercicio 1
bool estaOrdenado(const int arreglo[], unsigned int longitud);

// Ejercicio 2
bool esPrimo(int numero);

// Ejercicio 3
bool pertenece(int elemento, const int arreglo[], unsigned int longitud);

// Ejercicio 4
float desvioEstandar(const float arreglo[], unsigned int longitud);

// Ejercicio 5
long fibonacci(int k);

// Ejercicio 6
int maximoComunDivisor(int x, int y);

// Ejercicio 7
int sumaDoble(const int arreglo[], unsigned int longitud);

// Ejercicio 8
bool esCapicua(string palabra);

// Ejercicio 9
bool mismos(const int arreglo1[], const int arreglo2[], unsigned int longitud1, unsigned int longitud2);

// Ejercicio 10
bool esPrefijo(const string prefijo, const string palabra);

// Ejercicio 11
long maximoProductoEnSerie(string serie, unsigned int digitos);

// Ejercicio 12
long long minimoProductoEscalar(int v[], int u[], unsigned int len);

#endif //TALLER_INCLUDED_H
