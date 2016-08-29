#include <stdio.h>
static int i;
int main() 
{

  i = 0;
  add(0);
  return 0;

}

int add(int n)
{
  printf("i = %d\n  ", i++);
  return add(n + 1);
}
