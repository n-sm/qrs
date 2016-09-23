#include <iostream>
#include <math.h>
#include <cmath>
#include "taller.h"
#include <vector>
using namespace std;

bool estaOrdenado(const int arreglo[], unsigned int longitud);
bool esPrimo(int numero);
bool pertenece(int elemento, const int arreglo[], unsigned int longitud);
float desvioEstandar(const float arreglo[], unsigned int longitud);
long fibonacci(int k);
int maximoComunDivisor(int x, int y);
bool esCapicua(string palabra);
unsigned int cuenta(int e, const int a[], unsigned int l);
bool mismos(const int arreglo1[], const int arreglo2[],
	    unsigned int longitud1, unsigned int longitud2);


int main()
{
   esCapicua("1á1");
   return 0;
}
/* IMPORTANTE: <math.h> y <cmath> se incluyen
 * solo para que utilicen abs() y pow(),
 * si las neceistaran. No deben utilizar ninguna
 * otra funcionalidad de estas ni 
 * ninguna otra biblioteca. */

/************* Ejercicio 1 *************/



bool estaOrdenado(const int arreglo[], unsigned int longitud)
{
   if(longitud == 0)
      return true;
   int c = 0;
   for (unsigned int i = 1; i < longitud; i++)
   {
      if( arreglo[i -1] <= arreglo[i] )
	 c--;
      else
	 c++;
   }
   return abs(c) == (int) longitud - 1;
}

/************* Ejercicio 2 *************/

bool esPrimo(int numero)
{
   if (numero < 2)
      return false;

   for(int i = 2; i < numero; i++)
      if( numero % i == 0)
	 return false;
   return true;
}

/************* Ejercicio 3 *************/

bool pertenece(int elemento, const int arreglo[], unsigned int longitud)
{
   for(unsigned int i = 0; i < longitud; i++)
      if (arreglo[i] == elemento)
	 return true;
   return false;
}

/************* Ejercicio 4 *************/

float desvioEstandar(const float arreglo[], unsigned int longitud)
{
   float suma = 0;
   for(unsigned int i = 0; i< longitud; i++)
   {
      suma += arreglo[i];
   }
   float  media =  suma/longitud;

   float cuadrados = 0;

   for(unsigned int i = 0; i < longitud; i++)
   {
      cuadrados += pow(arreglo[i] - media, 2);
   }
   float var = cuadrados/longitud;
   return(pow(var,0.5));
}

/************* Ejercicio 5 *************/

long  fibonacci(int k)
{
   if( k == 0)
      return 0;
   long anteultimo = 1;
   long ultimo = 1;
   long tmp;

   for (int i = 2; i < k; i++)
   {
      tmp = ultimo;
      ultimo += anteultimo;
      anteultimo = tmp;
   }
   return ultimo;
}

/************* Ejercicio 6 *************/

int maximoComunDivisor(int x, int y)
{
   if (x == 0 || y == 0)
      return x > y ? x : y;
   int min = abs(x) < abs(y) ? abs(x) : abs(y);
   int mcd = 1;
   for(int i = 2; i <= min; i++)
   {
      if( x % i == 0 && y % i == 0)
	 mcd = i;
   }
   return mcd;
}

/************* Ejercicio 7 *************/

int sumaDoble(const int arreglo[], unsigned int longitud)
{
   int num, suma = 0;
   for(unsigned int i = 0; i < longitud; i++)
   {
      num = arreglo[i];
      if (num > 0 && num % 2 == 0)
	 suma += num + num;
   }
   return suma;
}

/************* Ejercicio 8 *************/

bool esCapicua(string palabra)
{
   int len = palabra.length();
   for (int i = 0; i < len/2; i++)
      if( palabra.at(i) != palabra.at(len - 1 - i) )
	 return false;

   return true;
}

/************* Ejercicio 9 *************/

bool mismos(const int arreglo1[], const int arreglo2[],
	    unsigned int longitud1, unsigned int longitud2)
{
   if( longitud1 != longitud2 )
      return false;
   for(unsigned int i = 0; i < longitud1; i++)
   {
      if(cuenta(arreglo1[i], arreglo2, longitud1) != cuenta(arreglo1[i], arreglo1, longitud1))
	 return false;
   }
   return true;
}

/************* Ejercicio 10 *************/

bool esPrefijo(const string prefijo, const string palabra)
{
   if (prefijo == "")
      return true;
   if (prefijo.length() > palabra.length())
      return false;
   int l = prefijo.length();
   for(int i = 0; i < l; i++)
   {
      if(prefijo.at(i) != palabra.at(i))
	 return false;
   }
   return true;
}

/************* Ejercicio 11 *************/

long maximoProductoEnSerie(string serie, unsigned int digitos)
{
    return 0;
}

/************* Ejercicio 12 *************/

long long minimoProductoEscalar(int v[], int u[], unsigned int len){
    return 0;
}

unsigned int cuenta(int e, const int a[], unsigned int l)
{
   unsigned int res = 0;
   for(unsigned int i = 0; i < l; i++)
   {
      if(a[i] == e)
	 res++;
   }
   return res;
}
