

#include <iostream>
using namespace std;

int f1() {
    return 1;
}

int f2() {
    return 2;
}

typedef int (*fptr)();


fptr f( char c ) {
    if ( c == '1' ) {
    	return f1;
    }
    else {
    	return f2;
    }
}

int main() {
    char c = '1';
    fptr fp = f( c );
    cout << fp() << endl;
}

