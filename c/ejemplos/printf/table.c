#include <stdio.h>

int main()
{
  printf("From http://www.cplusplus.com\n\n\
specifier\t\t	Output\t\t\t\t	Example\n\n\
d or i\t	Signed decimal integer\t\t\t\t	392\n\
u\t	Unsigned decimal integer\t\t\t	7235\n\
o\t	Unsigned octal\t\t\t\t\t	610\n\
x\t	Unsigned hexadecimal integer\t\t\t	7fa\n\
X\t	Unsigned hexadecimal integer (uppercase)\t	7FA\n\
f\t	Decimal floating point, lowercase\t\t	392.65\n\
F\t	Decimal floating point, uppercase\t\t	392.65\n\
e\t	Scientific notation (mantissa/exponent), lowercase	3.9265e+2\n\
E\t	Scientific notation (mantissa/exponent), uppercase	3.9265E+2\n\
g\t	Use the shortest representation: \%%e or %%f\t	392.65\n\
G\t	Use the shortest representation: %%E or %%F\t	392.65\n\
a\t	Hexadecimal floating point, lowercase\t\t	-0xc.90fep-2\n\
A\t	Hexadecimal floating point, uppercase\t\t	-0XC.90FEP-2\n\
c\t	Character\t\t\t\t\t	a\n\
s\t	String of characters\t\t\t\t	sample\n\
p\t	Pointer address\t\t\t\t\t	b8000000\n\
n\t	Nothing printed.\n\
 \t	The corresponding argument must be a pointer to a signed int.\n\
\t	The number of characters written so far is stored in the pointed location.\t\t\t\t	\n\
%%\t	A %% followed by another %% character \n\
\t	will write a single %% to the stream.\t\t\t	%% \n\
");

  return 0;
}
