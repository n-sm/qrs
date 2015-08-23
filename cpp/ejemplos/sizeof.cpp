#include <iostream>

int main(){
  char ch;
  int i;
  float f;
  double d;
  long int li;
  int* p;
  double* pd;
  char* pch;
  int arr[1];
  double darr[1];


  std::cout << "\n"
	    << "char:   " << sizeof(ch) << "\n"
	    << "int:    " << sizeof(i) << "\n"
	    << "float:  " << sizeof(f) << "\n"
	    << "double: " << sizeof(d) << "\n"
	    << "long:   " << sizeof(li) << "\n"
	    << "ptr-int " << sizeof(p) << "\n"
	    << "ptr-double " << sizeof(pd) << "\n"
	    << "ptr-char " << sizeof(pch) << "\n"
	    << "arr[1]-int " << sizeof(arr) << "\n"
	    << "arr[1]-double " << sizeof(darr) << "\n"
    ;
}
