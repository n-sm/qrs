#include <iostream>

bool todosPares(int a[], int n);

int main(int argc, char *argv[] )
{
   int a[7] = { 1,2,3,4,5,6,7 };
   int n = 3;
   std::cout << "Antes de todosPares: a[0] es: "
	     << a[0] << std::endl;
   bool test = todosPares(a, n);

   if (test == false)
   {
      std::cout << "Despues de todosPares: a[0] es: "
		<< a[0] << std::endl;
   }

   return 0;
}

bool todosPares(int a[], int n)
{
   bool result = true;
   if ( a[0] % 2 != 0 )
   {
      result = false;
      a[0] = a[0] + 1;
   }
   return result;
}
