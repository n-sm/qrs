#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define D_ 128

void printHelp();
void dameOrden (long long * desorden, int * ordenada);
int cantidadNoNulos(long long * arr);
int nOrden(long long i, long long * a);
void printInOrder(long long * desorden, int * orden);
  
int main( int argc, char *argv[] )  
{
  int d = 0;
  int changeOrder = 0;
  char c;
  char * strp;
    
  while ((c = getopt (argc, argv, "d:oh")) != -1)
    switch (c) {
      case 'd':
	d += atoi(optarg);
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
  for (int i = 0; i < 256; i++) {
    tabla[i] = 0;
  }

  tabla[256] = -1;
  
  while ((c = fgetc(stdin)) != EOF) {
      tabla[c - CHAR_MIN] += 1;
  }

  int caracteresUsados = 0;
  for (int i = 0; i < 256; i++) {
    if (tabla[i] != 0) {
      printf("%d: dec: %d \tchar: %c \tcount: %lld\n",
	     ++caracteresUsados, i + CHAR_MIN, i + CHAR_MIN, tabla[i]);
    }
  }

  int orde[257];
  orde[256]=-1;
  dameOrden(tabla, orde);
  
  /* printf("%d\n", cantidadNoNulos(tabla)); */
  /* for (int i = 0; i < 256; i++) { */
  /*   if(tabla[i] != 0) printf("deso: %lld, ord: %d\n", tabla[i], orde[i]); */
  /* } */

  printInOrder(tabla, orde);
  return 0;
}

void printHelp()
{
  printf("seco 0.0\n\nusage: seco [options] \n\nOptions:\n");
  printf("\t-d decimal\n\t-o determina el orden\n");
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
  
  /* printf("en dameOrden"); */
  /* pord = orden; */
  /* while(*pord != -1) { */
  /*   printf("%d\t", *++pord); */
  /* } */
}
  
int max (int * arr) {

  if (*arr == -1) abort();
  int c = 0;
  int res = *arr;
  int * p = arr;
  while (*p != -1) {
    //printf("%d.", *p++);
    if (res < *p) res = *p;
    /* if (c++ > 9999999) { */
    /*   printf("\nerror!: int * arr sin -1 final.\n"); */
    /*   abort(); */
    /* } */
    p++;
    if (p - arr > 258) {
      printf("\nerror!: int * arr sin -1 final.2\n");
      abort();
    }
  }
  return res;
}

void printInOrder(long long * desorden, int * orden) {


  int l = len(desorden);
  int m = max(orden);
  printf("\n---=-=-print in order\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < l; j++) {
      if (orden[j] == i)
	printf("%c: %lld\n", j+CHAR_MIN, desorden[j]);
    }
  }
  printf("\n");
  return;
}
