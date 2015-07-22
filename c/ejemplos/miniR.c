#include <stdio.h>



#define NUM_NODE_CLASSES 8
#define NUM_OLD_GENERATIONS 2

typedef unsigned int SEXPTYPE;
typedef int R_len_t;


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


struct vecsxp_struct {
    R_len_t	length;
    R_len_t	truelength;
};

struct primsxp_struct {
    int offset;
};

struct symsxp_struct {
    struct SEXPREC *pname;
    struct SEXPREC *value;
    struct SEXPREC *internal;
};

struct listsxp_struct {
    struct SEXPREC *carval;
    struct SEXPREC *cdrval;
    struct SEXPREC *tagval;
};

struct envsxp_struct {
    struct SEXPREC *frame;
    struct SEXPREC *enclos;
    struct SEXPREC *hashtab;
};

struct closxp_struct {
    struct SEXPREC *formals;
    struct SEXPREC *body;
    struct SEXPREC *env;
};

struct promsxp_struct {
    struct SEXPREC *value;
    struct SEXPREC *expr;
    struct SEXPREC *env;
};
#define SEXPREC_HEADER \
    struct sxpinfo_struct sxpinfo; \
    struct SEXPREC *attrib; \
    struct SEXPREC *gengc_next_node, *gengc_prev_node

/* The standard node structure consists of a header followed by the
   node data. */
typedef struct SEXPREC {
    SEXPREC_HEADER;
    union {
	struct primsxp_struct primsxp;
	struct symsxp_struct symsxp;
	struct listsxp_struct listsxp;
	struct envsxp_struct envsxp;
	struct closxp_struct closxp;
	struct promsxp_struct promsxp;
    } u;
} SEXPREC, *SEXP;


typedef union PAGE_HEADER {
  union PAGE_HEADER *next;
  double align;
} PAGE_HEADER;

static struct {
    SEXP Old[NUM_OLD_GENERATIONS], New, Free;
    SEXPREC OldPeg[NUM_OLD_GENERATIONS], NewPeg;
#ifndef EXPEL_OLD_TO_NEW
    SEXP OldToNew[NUM_OLD_GENERATIONS];
    SEXPREC OldToNewPeg[NUM_OLD_GENERATIONS];
#endif
    int OldCount[NUM_OLD_GENERATIONS], AllocCount, PageCount;
    PAGE_HEADER *pages;
} R_GenHeap[NUM_NODE_CLASSES], tgh;

static SEXPREC UnmarkedNodeTemplate;

void impr(SEXPREC sexpr) 
{

  printf("sexpr.sxpinfo.type: %d\n", sexpr.sxpinfo.type);
  printf("sexpr.sxpinfo.obj: %d\n", sexpr.sxpinfo.obj);
  printf("sexpr.sxpinfo.named: %d\n", sexpr.sxpinfo.named);
  printf("sexpr.sxpinfo.gp: %d\n", sexpr.sxpinfo.gp);
  printf("sexpr.sxpinfo.mark: %d\n", sexpr.sxpinfo.mark);
  printf("sexpr.sxpinfo.debug: %d\n", sexpr.sxpinfo.debug);
  printf("sexpr.sxpinfo.trace: %d\n", sexpr.sxpinfo.trace);
  printf("sexpr.sxpinfo.spare: %d\n", sexpr.sxpinfo.spare);
  printf("sexpr.sxpinfo.gcgen: %d\n", sexpr.sxpinfo.gcgen);
  printf("sexpr.sxpinfo.gccls: %d\n", sexpr.sxpinfo.gccls);
}

void imprp(SEXPREC *sexprp)
{
  printf("sexprp->sxpinfo.type: %d\n", sexprp->sxpinfo.type);
  printf("sexprp->sxpinfo.obj: %d\n", sexprp->sxpinfo.obj);
  printf("sexprp->sxpinfo.named: %d\n", sexprp->sxpinfo.named);
  printf("sexprp->sxpinfo.gp: %d\n", sexprp->sxpinfo.gp);
  printf("sexprp->sxpinfo.mark: %d\n", sexprp->sxpinfo.mark);
  printf("sexprp->sxpinfo.debug: %d\n", sexprp->sxpinfo.debug);
  printf("sexprp->sxpinfo.trace: %d\n", sexprp->sxpinfo.trace);
  printf("sexprp->sxpinfo.spare: %d\n", sexprp->sxpinfo.spare);
  printf("sexprp->sxpinfo.gcgen: %d\n", sexprp->sxpinfo.gcgen);
  printf("sexprp->sxpinfo.gccls: %d\n", sexprp->sxpinfo.gccls);

}
void main () 
{

  static SEXPREC testse;
  int tmp =  testse.sxpinfo.type;
  SEXPREC * ptrse = &testse;
  R_GenHeap[0].Free = &UnmarkedNodeTemplate;
  //  impr(testse);

  //impr(tgh.NewPeg);
  printf("\n\n\n");
  impr(R_GenHeap[0].NewPeg);
  printf("======\n=====\n");
  imprp(R_GenHeap[0].Free);
  //  printf("R_GenHeap[0].New.sxpinfo", 
  //  printf("R_GenHeap[0]: %d\n", R_GenHeap[0].Free);
}
