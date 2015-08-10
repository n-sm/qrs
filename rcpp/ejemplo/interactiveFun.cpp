/* Esto es solo un ejemplo. eEn si no tiene utilidad.
   Para usarlo desde R escribir:
   sourceCpp('fact.cpp')
*/

#include <Rcpp.h>

#define SIZE 100

using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
void main()
{
  int i;
  cout << "Ingrese un número: " << endl;
  cin >> i; 
  cout << "Numero ingresado:" << i << endl;
}
