#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


void printHelp();
void dameOrden (long long * desorden, int * ordenada);
int cantidadNoNulos(long long * arr);
int nOrden(long long i, long long * a);
void mostrarTablaConOrden(long long * desorden, int * orden);
void mostrarTabla (long long * tabla, int ordenada);

int main( int argc, char *argv[] )  
{
  int sort = 0;
  int d = 0;
  int changeOrder = 0;
  char c;
  char * strp;
    
  while ((c = getopt (argc, argv, "soh")) != -1)
    switch (c) {
      case 's':
	sort = 1;
        break;
      case 'h':
	printHelp();
	return 0;
      case 'o':
	changeOrder = 1;
	break;
      case '?':
        if (optopt == 'd' || optopt == 'o') {
	  printHelp();
	}
        else if (isprint (optopt)) {
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
	  printHelp();
	}
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
    }


  long long tabla[257];
  int i = 0;
  for (; i < 256; i++) {
    tabla[i] = 0;
  }
  tabla[256] = -1;
  
  while ((c = fgetc(stdin)) != EOF) {
      tabla[c - CHAR_MIN] += 1;
  }

  mostrarTabla(tabla, sort);


  return 0;
}

void printHelp()
{
  printf("seco 0.0\n\nusage: char-summary [options] \n\nOptions:\n");
  printf("\t-s sort\n");
}


int cantidadNoNulos(long long * arr) {

  /*
    Usamos como convencion que -1 indica el fin del arreglo, 
    como cuando usamos '\0' para denotar el de una string.
   */
  
  int c = 0;
  long long * p;
  p = arr;
  while(*p != -1) 
    if (*p++ > 0) c++;
  return c;

}

int len(long long * arr) {
  
  int res = 0;
  long long * p = arr;
  while (*p++ != -1)
    res++;
  return res;
}

int nOrden(long long i, long long * arr) {
  int res = 1;
  long long *p = arr;
  while(*p != -1) {
    if (i < *p++) res++;
  }
  return res;
    
}


void dameOrden(long long * desorden, int * orden) {
  
  long long * pdes = desorden;
  int * pord = orden;

  while(*pdes != -1) {
    *pord++ = nOrden(*pdes++, desorden);
  }
  *pord = -1;
}
  
int max (int * arr) {
  if (*arr == -1) abort();
  int c = 0;
  int res = *arr;
  int * p = arr;
  while (*p != -1) {
    if (res < *p) res = *p;
    p++;
    if (p - arr > 99999999) {
      printf("\nerror!: int * arr sin -1 final.2\n");
      abort();
    }
  }
  return res;
}

void mostrarTablaConOrden(long long * desorden, int * orden) {
  int l = len(desorden);
  int m = max(orden);
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < l; j++) {
      if (orden[j] == i)
	printf("%d \t%lld \t%c\n",
	       j + CHAR_MIN, desorden[j], j + CHAR_MIN);
    }
  }
  printf("\n");
  return;
}

void mostrarTablaSinOrden (long long * tabla) {
  int i;
 for ( i = 0; i < 256; i++) {
    if (tabla[i] != 0) {
      printf("%d \t%lld  \t%c\n",
	     i + CHAR_MIN, tabla[i], i + CHAR_MIN);
    }
  }
}

void mostrarTabla (long long * tabla, int ordenada) {

  int orden[257];

  printf("dec:\tcount:\tchar:\n");
  switch(ordenada) {
  case 0:
    mostrarTablaSinOrden(tabla);
    break;
  case 1:
    orden[256]=-1;
    dameOrden(tabla, orden);
    mostrarTablaConOrden(tabla, orden);
    break;


  }
}
