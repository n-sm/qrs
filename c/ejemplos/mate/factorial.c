#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long factorial(unsigned int n);
    
int main (int argc, char ** argv)
{
    for (int i = 1; i < argc; i++)
    {
	printf ("%llu\n", factorial(atoi(argv[i])));
    }
}

unsigned long long factorial(unsigned int n)
{
   unsigned long long res = 1;
   for (unsigned int i = n; i > 0; i--)
   {
       if ( res > ULLONG_MAX / i )
       {
	   printf ("error: UUL overflow\n");
	   abort();
       }
      res *= i;
   }
   return res;
}
