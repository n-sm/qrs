#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define DESDE 0L
#define HASTA 25L
// http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format

#define BYTETOBINPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBIN(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0) 
#define PRBIN(x) printf(# x " es "BYTETOBINPATTERN"\n",	\
   BYTETOBIN(x))

int pot(int x, int y);
char * itobin(int decimal);
char *ltobin(long decimal, int bytes);
char * dtobin(long decimal, int bytes);
int main(int argc, char ** argv)
{
  long desde, hasta, decimal, test;
  if (argc > 1) {
    desde = atoi(argv[1]);
    if (argc > 2)
      hasta = atoi(argv[2]);
    else hasta = desde;
  }
  else {
    desde = DESDE;
    hasta = HASTA;
  }
  decimal = 1L;

  //  printf("\nPRBIN: ");
  //  PRBIN(decimal);
  //  for(decimal = 0; decimal < 5; decimal++)
  //  printf("%s\n", ltobin(decimal, 8));
  //  printf("%s\n", itobin(decimal));

  test = 1L << decimal;
  //  printf("lmax %s\n", ltobin(9223372036854775807, 8));
  for(decimal = desde; decimal < hasta; decimal++){
    printf("\n%ld l to\n%s", decimal, ltobin(decimal, 18));
    printf("\n%ld d to\n%s", decimal, dtobin(decimal, 18));
    //    printf("\n%d\n%s", decimal, dtobin(decimal, 18));
  }
  printf("\n");

  //PRBIN(32);
  return 0;

}

int pot(int x, int y)
{
  int i, ret = 1;
  
  for (i = 0; i < y; i++)
    ret *= x;
  return ret;
}

char * itobin(int decimal)
{
  
  unsigned long size = sizeof(decimal);
  // char es 1, short es 2, int es 4, long es 8.
  // Ya sabemos q es int, por lo que no hace falta
  // en realidad.
  
  char * ret = malloc(size * 9);
  int i;
  for (i = 0; i < size * 9; i++) {
    if (! (i % 8)) {
      ret[i] = ' ';
      continue;
    }
    ret[i] = (pot(2, size * 8  - i) & decimal) ? '1' : '0';
  }
  ret[size * 8 + 1] = '\0';
  return ret;
}


char *ltobin(long decimal, int bytes)
{
  
  unsigned long size = sizeof(decimal);
  // char es 1, short es 2, int es 4, long es 8.
  // Ya sabemos q es int, por lo que no hace falta
  // en realidad.
  
  char * ret = malloc(size * 8 /*+ 1*/);
  int i, comparar;
  for (i = 0; i < size * 8/* + 1*/; i++) {
    comparar = pot(2, size * 8   - i - 1);
    //printf("comp: %d", comp);
    ret[i] = (comparar & decimal) ? '1' : '0';
    
  }
  ret[size * 8 /* + 1*/] = '\0';
  //  ret += (size * 8);// - bytes * 9 )  ;
  return ret;
}

char * dtobin(long decimal, int bytes)
{
  unsigned long comparar, size = sizeof(decimal);

  char * ret = malloc(size * 8 /*+ 1*/);
  int i;
  for (i = 0; i < size * 8 /* + 1*/; i++) {
    comparar = 1L << i;
    //printf("comp: %d", comp);
    ret[size * 8 - 1 - i] = (comparar & decimal) ? '1' : '0';
  }
  ret[size * 8 /* + 1*/] = '\0';
  return ret;
}
