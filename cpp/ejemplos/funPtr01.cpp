
#include <iostream>
using namespace std;

int f1(int par) {   return par;}
int f2(int par) {   return par;}
typedef int (*fptr)(int);
fptr f( char c ) {
    if ( c == '1' ) {
    	return f1;
    }
    else {
    	return f2;
    }
}

int main() {
  int p;
  p = 89;
    char c = '1';
    fptr fp = f( c );
    cout << fp(p) << endl;
}
