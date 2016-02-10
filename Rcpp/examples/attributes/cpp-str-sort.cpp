#include <Rcpp.h>
using namespace Rcpp;
 
// [[Rcpp::export]]
std::vector< std::string > cpp_str_sort( std::vector< std::string > sv ) {
  
  int len = sv.size();
 
  for( int i=0; i < len; i++ ) {
    std::sort( sv[i].begin(), sv[i].end() );
  }
  
  return sv;
}
