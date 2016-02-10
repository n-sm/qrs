//#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector< std::string> split (std::string  s)
{
  std::vector< std::string> retsv;

  int desde;
  int c = 0;
  int i = 0;
  int len = s.size();
  while(s[i] == ' ') i++;
  desde = i;
  for(; i < len ; i++)
    {
      if (s[i] == ' ') {
	if(s[i+1] == ' ') continue;
	std::string tmpstr( s.substr(desde, i - desde) );
	retsv.insert(retsv.begin() + c++, tmpstr) ;
	desde = i + 1;
      }
    }
  // i == len - 1
  std::string tmpstr( s.substr(desde, ++i - desde ) );
  retsv.insert(retsv.begin() + c, tmpstr) ;

  return retsv;
}
std::vector< std::string> splitIter (std::string  s)
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


int main()
{
  std::string s = std::string("una Stri ng con   Espacios  para split !!!!");
  std::vector< std::string > vecStrRes = splitRes(s);

  std::cout << "splitRes:\n";
  for(std::vector< std::string >::iterator it = vecStrRes.begin();
      it != vecStrRes.end();
      ++it)
    std::cout << it - vecStrRes.begin() << "vecStr: "
	      << *it << std::endl;
  
    return 0;
}


