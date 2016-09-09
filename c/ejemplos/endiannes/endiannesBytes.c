#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

void get_endiannes();
void get_endiannes2();
void mostrar_unsigned(unsigned long l);
void mostrar_signed(long l);
void prhelp();

int main(int argc, char *argv[]) 
{

   char c;
   int unsignedlong = 0;
   
   while ((c = getopt (argc, argv, "hs")) != -1)
      switch (c)
      {
	 case 'h':
	    prhelp();
	    return 0;
	 case 's':
	    unsignedlong = 1;
	    break;
	 case '?':
	    if (isprint (optopt))
	    {
	       fprintf (stderr, "Unknown option `-%c'.\n", optopt);
	       prhelp();
	    }
	    else
	       fprintf (stderr,
			"Unknown option character `\\x%x'.\n",
			optopt);
	    return 1;
	 default:
	    abort ();
	
      }
      
   printf("Endiannes: \n");
   get_endiannes();
   printf("\n");
   get_endiannes2();
   printf("\n");

   if (argc == 1)
   {
      printf("Debe proporcionar algun parametro.\n");
      prhelp();
      return 1;
   }
   if (unsignedlong)
      mostrar_signed(atoll(argv[1]));
   else
      mostrar_unsigned(atoll(argv[1]));
   return 0;
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

void mostrar_unsigned(unsigned long l)
{
   union
   {
      unsigned long l;
      unsigned char c[8];
   } un;
   un.l = l;
   printf("numero: %ld\n", l);
   for (int i = 0; i < 12; i++)
   {
      if(i == 8) printf("(me paso)\n");
      printf("lugar numero %d, ie c[%d]: %d\n", i, i,un.c[i]);
   }
}

void mostrar_signed(long l)
{
   union
   {
      long l;
      char c[8];
   } un;
   un.l = l;

   printf("numero: %ld\n", l);
   for (int i = 0; i < 12; i++)
   {
      if(i == 8) printf("(me paso)\n");
      printf("lugar numero %d, ie c[%d]: %d\n", i, i,un.c[i]);
   }
}
    
void prhelp()
{
   printf("usage: prog NUMBER\n");
   printf("Guarda el numero en un unsigned long y muestra uno a uno\n");
   printf("el byte de todo el lugar de la memoria donde esta.\n");
}
