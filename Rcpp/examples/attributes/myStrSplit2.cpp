// TODO: 
#include <stdio.h>
#include <Rcpp.h>

using namespace Rcpp;


std::vector< std::string> split (std::string  s)
{
  std::vector< std::string> retsv;
  std::string::iterator desde = s.begin();
  std::string::iterator it;
  for( it = s.begin(); it != s.end(); ++it)
    {

      if (*it == ' ' ) {
	std::string tmpstr = std::string(desde, it);
	desde = it + 1;
	retsv.push_back( tmpstr );
      }
    }

  std::string tmpstr = std::string(desde, it + 1);
  desde = it + 1;
  retsv.push_back( tmpstr );
  return retsv;
}

// [[Rcpp::export]]
std::vector< std::string> myStrSplit (std::vector< std::string > sv)
{
  std::vector< std::string > retsv;
  int len = sv.size();
 
  for( int i=0; i < len; i++ ) {
    //std::replace( sv[i].begin(), sv[i].end(), ' ', '\n' );
    std::vector< std::string > tmpsv = split(sv[i]);
    retsv.insert(retsv.end(), tmpsv.begin(), tmpsv.end());
    
  }

  return retsv;
}
  
