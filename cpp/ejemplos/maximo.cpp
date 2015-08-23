#include <iostream>

int main(){
  int i = 0;
  int j = 1;
  int *p, *q;

  p = &i;
  q = &j;

  for(; i < 99; i++, q++)
    std::cout << *q << " ";

}

