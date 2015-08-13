#include <iostream>

const int MAXV = 9;
const int F = 0;
//typedef int (*fptr)(int);

int N(int p);
int Id(int p);
int Y(int p, int q);
int C(int p, int q);
int O(int p, int q);
int test1v(int (*fptr)(int));
int test2v(int (*fptr)(int, int));

int N(int p){ return !p;}
int Id(int p){ return p;}
int Y(int p, int q){ return!(!p || !q);}
int C(int p, int q){ return(!p || q);}
int O(int p, int q){ return(p || q);}

int test1v(int (*fptr)(int)){
  int p;
  for(p=0; p<2 ; ++p){
    std::cout << "si p = " << p << ", luego  " << (*fptr)(p) << "\n";
  }
};

int test2v(int (*fptr)(int, int)){
  int p, q;
  for(p = 0 ; p < 2 ; ++p){
    for(q = 0; q < 2 ; ++q){
      std::cout << "si p = " << p << " y q = " << q << ", luego: " << (*fptr)(p, q) << "\n";
    }
  }
}

int main(){
  int (*f)(int);
  f = N;
  std::cout << "  f = N\n";
  std::cout << "*f: " << *f << "\n";
  std::cout << "f: " << f << "\n";
  std::cout <<  "Aca N(1): " << (*f)(1) << "\n";
  f = Id;
  std::cout << "  f = Id\n";
  std::cout << "*f: " << *f << "\n";
  std::cout << "f: " << f << "\n";
  std::cout <<  "Aca Id(1): " << (*f)(1) << "\n";
  std::cout << "\nTest de N:\n";
  test1v(N);
  std::cout << "\nTest de Y:\n";
  test2v(Y);

}

