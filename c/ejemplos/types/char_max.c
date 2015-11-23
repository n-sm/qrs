#include <limits.h>
#include <stdio.h>
int main(){

printf("\n\
CHAR_BIT %d\n\
CHAR_MAX %d\n\
CHAR_MIN %d\n\
INT_MAX %d\n\
INT_MIN %d\n\
LONG_MAX %ld\n\
LONG_MIN %ld\n\
SCHAR_MAX %d\n\
SCHAR_MIN %d\n\
SHRT_MAX %d\n\
SHRT_MIN %d\n\
UCHAR_MAX %d\n\
UINT_MAX %d\n\
ULONG_MAX %ld\n\
USHRT_MAX %d\n\n\
",
       CHAR_BIT,\
CHAR_MAX,\
CHAR_MIN,\
INT_MAX,\
INT_MIN,\
LONG_MAX,\
LONG_MIN,\
SCHAR_MAX,\
SCHAR_MIN,\
SHRT_MAX,\
SHRT_MIN,\
UCHAR_MAX,\
UINT_MAX,\
ULONG_MAX,\
       USHRT_MAX);
 int i = 1300;
 char c = 1;
 printf("Hago cast de int to char donde int > CHAR_MAX\n");
 printf("i = %d\nc = %d es %c \n", i, c, c);
 printf("printf %%d de (char) i es: %d\n", (char) i);
 
  return 0;
}
