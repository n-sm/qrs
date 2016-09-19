#include <iostream>
#include <stdio.h>


int main ()
{
  char c;

  while (std::cin.get(c)) {
    putchar(c+1);
  }
  return 0;
}
