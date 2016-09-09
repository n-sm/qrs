#include <stdio.h>
#include <stdlib.h>

#define DESDE 0
#define HASTA 25

// http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
#define BYTETOBINPATTERN "%d%d%d%d%d%d%d%d"
/*
  0x01, ..., 0x80 son simplemente las potencias de 2 en hexadecimal.
 */
#define BYTETOBIN(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0) 
#define PRBIN(x) printf("%"# x " es "BYTETOBINPATTERN"\n"\
  ,i , BYTETOBIN(x))

int main(int argc, char ** argv)
{
  int desde, hasta;
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
    
  int i;
  for(i = desde; i < hasta + 1; i++) PRBIN(i);
  return 0;
}
