#include <stdio.h>
#include <Rcpp.h>

using namespace Rcpp;

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

// [[Rcpp::export]]
std::vector< std::string> myStrSplit (std::vector< std::string > sv)
{
  std::vector< std::string > retsv;
  int len = sv.size();
 
  for( int i=0; i < len; i++ ) {
    std::vector< std::string > tmpsv = split(sv[i]);
    retsv.insert(retsv.end(), tmpsv.begin(), tmpsv.end());
  }
  return retsv;
}
