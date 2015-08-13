#include <iostream>
#include <vector>

const int MAXV = 9;
const int F = 0;
//typedef int (*fptr)(int);

std::vector<int> N(std::vector<int> p);
std::vector<int> Id(std::vector<int> p);

std::vector<int> Y(std::vector<int> p);

int C(int p, int q);
int O(int p, int q);

int test(std::vector<int> (*fptr)(std::vector<int>));

/*
int test2v(int (*fptr)(int, int));
*/
std::vector<int> N(std::vector<int> p){ 
  //  std::vector<int> retu(!p[0]);
  std::vector<int> retu(1,!p[0]);
  return retu;
}
std::vector<int> Id(std::vector<int> p){ 
  std::vector<int> retu(1,p[0]);
  return retu;
}

std::vector<int> Y(std::vector<int> p){
  std::vector<int> retu(1, !(!p[0] || !p[1]));
  return retu;
}



int C(int p, int q){ return(!p || q);}
int O(int p, int q){ return(p || q);}

int test(std::vector<int> (*fptr)(std::vector<int>)){
  int p;
  std::vector<int> pvec(1,1);
  for(p=0; p<2 ; ++p){
    pvec.assign(1,p);
    std::cout << "si p = " << p << ", luego  " << (*fptr)(pvec)[0] << "\n";
  }
}

/*

int test2v(int (*fptr)(int, int)){
  int p, q;
  for(p = 0 ; p < 2 ; ++p){
    for(q = 0; q < 2 ; ++q){
      std::cout << "si p = " << p << " y q = " << q << ", luego: " << (*fptr)(p, q) << "\n";
    }
  }
}
*/

int main(){
  int c;
  //  int (*f)(int);
  std::vector<int> interpr1(2,1);
  std::vector<int> interpr2(2,0);

  std::cout << "\n";
  std::cout <<  Y(interpr1)[0];
  std::cout <<  Y(interpr2)[0];
  std::cout << "\n y aca ... \n";
  test(N);
}

