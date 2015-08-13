// basic file operations
#include <iostream>
#include <fstream>
using namespace std;
int a = 13;
int main () {
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << a ;
  myfile.close();
  return 0;
}
