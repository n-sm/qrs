#include <iostream>
#include <fstream>
#include <stdio.h>
#define N 3
using namespace std;

// main() is where program execution begins.

char rta;
int i;
int a[N];
int main()
{
  for(i = 0; i < N; ++i)
    { cout << i << endl;
      cout << "Ingrese su respuesta (a, b o c): ";
      cin >> rta;
      while((rta != 'a') && (rta != 'b') && (rta != 'c'))
	{cout << "Debe ingresar 'a', 'b' o 'c'. ";
	  cin >> rta;
	}
      a[i] = rta;
     }
  printf("as %d", a[0]);
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << *a << endl;
  myfile.close();
  return 0;
}
  
