#include <iostream>

const int MAXV = 9;
const int F = 0;
typedef int (*fptr)(int);


int N(int p);
int Y(int p, int q);
int C(int p, int q);
int O(int p, int q);

int N(int p){ return !p;}
int Y(int p, int q){ return!(!p || !q);}
int C(int p, int q){ return(!p || q);}
int O(int p, int q){ return(p || q);}

fptr testN(){  return N; };

double test_validez(int (*f)(int p, int q)){
  int i, j;
  double count = 0;
  for(i=0; i<2; ++i){
    for(j=0; j<2; ++j){
      if((*f)(i,j) == 1) ++count;
    }
  }
  return count/(i*j);
}

int main(){

  //  fptr enmain;
  //enmain = test_validez(Y);

  std::cout << "\n";
  std::cout << test_validez(C) << "\n";
  std::cout <<  "\n";

}

