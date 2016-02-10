// from ocrad
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>


int hypoti( const int c1, const int c2 )
{
  long long temp = c1; temp *= temp;
  long long target = c2; target *= target; target += temp;
  int lower = std::max( std::abs( c1 ), std::abs( c2 ) );
  int upper = std::abs( c1 ) + std::abs( c2 );
  while( upper - lower > 1 )
    {
    int m = ( lower + upper ) / 2;
    temp = m; temp *= temp;
    if( temp < target ) lower = m; else upper = m;
    }
  temp = lower; temp *= temp; target *= 2; target -= temp;
  temp = upper; temp *= temp;
  if( target < temp ) return lower;
  else return upper;
}

int main()
{
  int a, b; a = 3, b = 4;
  std::cout << "a: " << a << " b: " << b
	    << " hypoti(a, b): " << hypoti(a, b) << '\n';
  return 0;
}
  
