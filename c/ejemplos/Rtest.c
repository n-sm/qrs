/*
Acc se incluyen algunas partes del codigo de R para estudiarlo.
Rinternals.h se encuentra en R-3.1.2/src/include/Rinternals.h
 */

#include <stdio.h>

// Rinternals.h l102
typedef unsigned int SEXPTYPE;


// Rinternals.h l[184:200] 

struct sxpinfo_struct {
    SEXPTYPE type      :  5;/* ==> (FUNSXP == 99) %% 2^5 == 3 == CLOSXP
			     * -> warning: `type' is narrower than values
			     *              of its type
			     * when SEXPTYPE was an enum */
    unsigned int obj   :  1;
    unsigned int named :  2;
    unsigned int gp    : 16;
    unsigned int mark  :  1;
    unsigned int debug :  1;
    unsigned int trace :  1;  /* functions and memory tracing */
    unsigned int spare :  1;  /* currently unused */
    unsigned int gcgen :  1;  /* old generation number */
    unsigned int gccls :  3;  /* node class */
}; /*		    Tot: 32 */

void main() 
{
  struct sxpinfo_struct test;
  test.type = 23;

  printf("test type es: %d\n", test.type);
}
