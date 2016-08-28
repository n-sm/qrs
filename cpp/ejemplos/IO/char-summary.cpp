#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <stdio.h>
//#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

unsigned char ch2uch(char c);
char uch2ch(unsigned char uc);
char maxCountIndx(std::map <char, long long> mapa);
int nOrden(long long i, std::map<char, long long> mapa);
void getOrder(std::map<char, long long> desorden,
	      std::vector<int>& orden);
void mostrarTablaSinOrden(std::map<char, long long> desorden);
void mostrarTablaConOrden(std::map<char, long long> desorden,
			  std::vector<int> orden);

int main( int argc, char *argv[] )  
{
  char c;

  while ((c = getopt (argc, argv, "abc")) != -1) {
    switch (c) {
    case 'a':
      std::cout << "caso a\n";
      return 0;
      break;
    case 'b':
      std::cout << "caso b\n";
      return 0;
    case 'c':
      return 0;
      break;
    case '?':
      if (optopt == 'd' || optopt == 'o') {
      }
      else if (isprint (optopt)) {
	fprintf (stderr, "Unknown option `-%c'.\n", optopt);
      }
      else
	fprintf (stderr,
		 "Unknown option character `\\x%x'.\n",
		 optopt);
      return 1;
    default:
      abort ();
    }
  }
  // termina getopt

  std::map<char, long long> chars;
  while (std::cin.get(c))
    chars[c] += 1;
  

  c = CHAR_MIN;
  std::cout << "dec: \tcount: \t char:\n";
  mostrarTablaSinOrden(chars);

  // probando orden
  std::vector<int> orden(UCHAR_MAX);
  getOrder(chars, orden);
  int ii = 0;
  for( std::vector<int>::iterator it = orden.begin();
      it != orden.end();
      it++, ii++) {
    if (*it > 0)
      std::cout <<"ii:"<< ii << "*it:"<< *it << std::endl;
  }

  std::cout << "==========\n";
  mostrarTablaConOrden(chars, orden);


  return 0;
}

unsigned char ch2uch(char c) { return c - CHAR_MIN; }
char uch2ch(unsigned char uc) { return uc + CHAR_MIN; }


char maxCountIndx(std::map <char, long long> mapa) {
  char c = CHAR_MIN, res = CHAR_MIN;
  long long max = mapa[c];
  
  while(++c != CHAR_MIN) 
    if(mapa[c] > mapa[res]) res = c;
  
  return res;
}


int nOrden(long long i, std::map<char, long long> mapa) {
  int  res = 1;
  std::map<char, long long>::iterator it;

  for( it = mapa.begin(); it != mapa.end(); it++) {
    if (i < it->second) res++;
  }
  return res;
}

void getOrder(std::map<char, long long> desorden,
	      std::vector<int>& orden) {

  std::map<char, long long>::iterator itdes = desorden.begin();
  std::vector<int>::iterator itord = orden.begin();
  for(; itdes != desorden.end(); itdes++, itord++) {
    *itord = nOrden(itdes->second, desorden);
    
  }
}

void mostrarTablaConOrden(std::map<char, long long> desorden,
			  std::vector<int> orden) {

  int ultimo = *std::max_element(orden.begin(), orden.end());

  for (int i = 1; i < ultimo; i++) {
    for (int j = 0; j < desorden.size(); j++) {
      if (orden[j] == i) {
	printf("orden[j]: %d, i: %d",orden[j], i);
	// printf("%d \t%lld \t%c\n",
      	//        j + CHAR_MIN +1, desorden[j + CHAR_MIN+1], j + CHAR_MIN+1);
	abort();
      }
    }
  }
  printf("\n");
}


void mostrarTablaSinOrden(std::map<char, long long> desorden) {
  char c = CHAR_MIN;
  while(++c != CHAR_MIN) {
    if (desorden[c] > 0)
      printf("%d \t%lld \t%c\n", c, desorden[c], c);
  }
}
