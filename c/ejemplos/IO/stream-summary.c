#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define D_ 128

void printHelp();
void orden (long long * desorden, long long * ordenada);

  
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

  for (int i = 0; i < 256; i++) {
    if (tabla[i] != 0) {
      printf("dec: %d \tchar: %c \tcount: %lld\n",
	     i + CHAR_MIN, i + CHAR_MIN, tabla[i]);
    }
  }

  long long  ordenada[257];
  orden(tabla, ordenada);
  long long * p = ordenada;
  while(*p != -1) {
    printf("%lld\t", *p++);
  }

  printf("\n");
  return 0;
}

void printHelp()
{
  printf("seco 0.0\n\nusage: seco [options] \n\nOptions:\n");
  printf("\t-d decimal\n\t-o determina el orden\n");
}

void orden(long long * desorden, long long * ordenada) {

  int c = 0;
  long long * p;
  p = desorden;

  while(*p != -1) {
    if (*p > 0) 
      ordenada[c++] = *p;
    p++;
  }
  ordenada[c] = -1;
}

