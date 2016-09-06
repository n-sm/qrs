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
   printf("\n");

   test(atoll(argv[1]));
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

void test(long l)
{
   union
   {
      unsigned long l;
      char c[8];

   } un;

   un.l = l;

   for (int i = 0; i < 12; i++)
   {
      if(i == 8) printf("(me paso)\n");
      printf("lugar numero %d, ie c[%d]: %d\n", i, i,un.c[i]);
   }
}
    
