#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define CHAR_PR_MIN 32

#define endl printf("\n")
#define tab printf("\t")

#define UORD(A) ((unsigned char) ((A) - CHAR_PR_MIN))
//#define UORD_TO_CHAR(UO) ((char) (UO + CHAR_PR_MIN))

#define CHARS_TO_SEMI(C1, C2)			\
   (((char) (~(~UORD(C1) &  ~(UORD(C2)) << 4))) - CHAR_MIN)

/* #define CHARS_TO_SEMI(C1, C2)			\ */
/*    (((char) (UORD(C1) &  (UORD(C2) << 4))) - CHAR_MIN) */


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

#define PRBIN(x) printf(BYTETOBINPATTERN,	\
			 BYTETOBIN(x))

void prhelp();

int main(int argc, char *argv[]) 
{
   if (argc == 1)
   {
      prhelp();
      return 0;
   }
   
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

   char *s = argv[1];
   char prm, sgd, semi;
   prm = s[0];
   sgd = s[1];
   printf("\tchar\tuord()\tbin\n");
   printf("a:\t%c\t%d\t", prm, UORD(prm));
   PRBIN(UORD(prm));
   endl;
   printf("b:\t%c\t%d\t", sgd, UORD(sgd));
   PRBIN(UORD(sgd));
   endl;
   
   //int counter = 0; 
   /* while (*s != '\0') */
   /* { */
   /*    if (counter % 2  == 0) */
   /*    { */
   /* 	 prm = *s; */
   /*    } */
   /*    else */
   /*    { */
   /* 	 sgd = *s; */
   /* 	 semi = CHARS_TO_SEMI(prm, sgd); */
   /* 	 // input as chars */
   /* 	 printf("chars:\tprm es %c,\tsgd es %c\n", prm, sgd); */
   /* 	 // input as nro ord */
   /* 	 printf("ord:\tprm es %d,\tsgd es %d\tsuma: %d\n", */
   /* 		UORD(prm), UORD(sgd), UORD(prm) + UORD(sgd)); */
   /* 	 // bitwise */
   /* 	 printf("UORD(sgd) << 4 es: %d\n", UORD(sgd) << 4); */
   /* 	 // binario */
   /* 	 printf("semi binario es:\t"); */
   /* 	 PRBIN(semi); */
   /* 	 printf("\n"); */
   /* 	 printf("en uchar:\t%d\n", semi); */

   /*    } */
      
   /*    s++; */
   /*    counter++; */
   /* } */


   printf("\n");
   return 0;
   }
    
   void prhelp()
   {
      printf("hacer...\n");
   }
