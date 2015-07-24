#include <stdio.h>

int main() 
{
  add(0);
}

int add(int n)
{
  return n + add(n + 1);
}
