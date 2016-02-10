//#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


std::vector< std::string> split (std::string  s)
{
  std::vector< std::string> retsv;
  std::string::iterator desde = s.begin();
  
  for(std::string::iterator it = s.begin(); it != s.end(); ++it)
    {

      if (*it == ' ' || it == s.end() - 1) {
	std::string tmpstr = std::string(desde, it + 1);
	desde = it + 1;
	retsv.push_back( tmpstr );
      }
    }
  return retsv;
}

void prs(size_t size, std::string s)
{
  std::cout << "sizeof  '" << s << "': "
	    <<  size << std::endl;
}  

int main()
{
  /*
  //  std::string s = std::string("una string para split l,");
  std::string s = std::string("unaStringSinEspacios");
  std::vector< std::string > vecStr = split(s);

  for(std::vector< std::string >::iterator it = vecStr.begin();
      it != vecStr.end();
      ++it)
    std::cout << "vecStr: " << *it << std::endl;
  */

  std::vector<int> voi;
  std::vector<std::string> vos;

  prs(sizeof(int), "int");
  prs(sizeof(char), "char");
  prs(sizeof(std::string), "std::string");
  prs(sizeof(voi), "voi = vector<int>;");
  prs(sizeof(vos), "vector<string>");
  
  std::vector<int> voi2;
  std::vector<std::string> vos2;
  prs( sizeof(voi2), "voi = vector<int>;");
  prs( sizeof(vos2), "vector<string>(9999)");

  std::cout << "\nCapacity of vos2: " << vos2.capacity() << std::endl;;
  int desde = 0;
  int hasta = 999999;
  std::cout << "\nEmpieza for... desde " << desde
	    << " hasta " << hasta << "\n\n";

  size_t size = 0;  
  for(; desde < hasta; desde++) {
    voi2.insert(voi2.begin() + desde, desde);
    if( size < voi2.capacity()) {
      std::cout << "size es " << size
		<< "\t\tvoi2.capacity() es"
		<< voi2.capacity() << "\t\tdesde es "
		<< "\t\tvoi2.size() es"
		<< voi2.size() << "\t\tdesde es "
	
		<< desde << std::endl;
      size = voi2.capacity();
    }
    //else std::cout << "no";
  }
  std::cout << " Termino for.\n";

  prs(sizeof(voi2), "voi2 = vector<int>, despues del for");

  //  int size = voi.size();
  std::cout << "Size of voi: " << voi.size() << std::endl;
  std::cout << "Size of voi2: " << voi2.size() << std::endl;
  //std::vector<int> myints = { 1, 2, 3, 4 };
  //std::cout << "0. size: " << myints.size() << '\n';

  return 0;
}
