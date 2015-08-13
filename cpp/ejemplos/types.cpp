#include <iostream>

#include <limits>

int main(){

  std::cout << "             " << "min" << "            max\n";

 
  char a, b;
  a = 0;
  b = a++;
  while(a > b){ ++a; ++b;}
  std::cout << "char      " << int(a) << "                 " << int(b) << "\n";

  short int i, j;
  i = 0;  
  j = i++;
  while(i > j){ ++i; ++j;}
  std::cout << "short int " << i << "                      " << j << "\n";

  int k, l;
  k = 0;  
  l = k++;
  while(k > l){ ++k; ++l;}
  std::cout << "int       " << k << "              " << l << "\n";
  
  float f, g;
  f = 0;  
  g = f++;
  while(f > g){ ++f; ++g;}
  std::cout << "float       " << f << "              " << g << "\n";

  // estos q siguen tardan mucho...

  long int m, n;
  m = 0;  
  n = m++;
  while(i > j){ ++m; ++n;}
  std::cout << "long int " << m  << "                 " << n << "\n";

  double d, e;
  d = 0;  
  e = d++;
  while(d > e){ ++d; ++e;}
  std::cout << "double       " << d << "              " << e << "\n";

  long double p, q;
  p = 0;  
  q = d++;
  while(d > e){ ++d; ++e;}
  std::cout << "l double       " << p << "              " << q << "\n";

  }

