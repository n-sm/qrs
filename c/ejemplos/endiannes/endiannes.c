#include "stdio.h"
#include "stdlib.h"

void get_endiannes();
void get_endiannes2();
void test();

int main(int argc, char *argv[]) 
{
   printf("Endiannes: \n");
   get_endiannes();
   printf("\n");
   get_endiannes2();
}

void get_endiannes()
{
   union {
      long l;
      char c[4];
   } u;
   u.l = 1;
   printf("get_endiannes:");
   if ( u.c[3] && !u.c[2] && !u.c[1] && !u.c[0] )  {
      // ORDER_BIGENDIAN
      printf("big endian");
   } else if ( !u.c[3] && !u.c[2] && !u.c[1] && u.c[0] ) {
      // ORDER_LITTLEENDIAN;
      printf("little endian");
   } else    //  ORDER_UNKNOWN
      printf("unknown endiannes");
}

void get_endiannes2()
{
   int num = 1;
   printf("get_endiannes2: ");
   if (*(char *)&num == 1)
   {
      printf("Little-Endian\n");
   }
   else
   {
      printf("Big-Endian\n");
   }
}
