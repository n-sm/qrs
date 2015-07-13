/*
/R-3.1.2/src/main/array.c
line 391.
 */

SEXP attribute_hidden do_length(SEXP call, SEXP op, SEXP args, SEXP rho)
{
    checkArity(op, args);
    check1arg(args, call, "x");

    SEXP x = CAR(args), ans;

    if (isObject(x) &&
       DispatchOrEval(call, op, "length", args, rho, &ans, 0, 1)) {
	if (length(ans) == 1 && TYPEOF(ans) == REALSXP) {
	    double d = REAL(ans)[0];
	    if (R_FINITE(d) && d >= 0. && d <= INT_MAX && floor(d) == d)
		return coerceVector(ans, INTSXP);
	}
	return(ans);
    }

#ifdef LONG_VECTOR_SUPPORT
    // or use IS_LONG_VEC
    R_xlen_t len = xlength(x);
    if (len > INT_MAX) return ScalarReal((double) len);
#endif
    return ScalarInteger(length(x));
}

/*
Hay que averiguar respecto de:
checkArity(op, args)
checklarg(args, call, "x")
CAR(args)
*/
//Rinternals.h
#define CAR(e)		((e)->u.listsxp.carval)

// isObject(x)
*/
//en include/Rinternals.h
#define isObject		Rf_isObject
#undef isObject
#define isObject(s)	(OBJECT(s) != 0)
#define OBJECT(x)	((x)->sxpinfo.obj)

/*
DispatchOrEval(call, op, "length", args, rho, &ans, 0, 1))
length(ans)
*/
//Rinternals.h
#define length(x)		Rf_length(x)
R_len_t  Rf_length(SEXP);

/*
TYPEOF(ans)
REALSXP
REAL(ans)
R_FINITE(d)
INT_MAX
floor(d)
coerceVector(ans, INTSXP)
ScalarReal((double) len)
ScalarInteger(length(x))
*/
//Rinlinefuns.h

INLINE_FUN SEXP ScalarInteger(int x)
{
    SEXP ans = allocVector(INTSXP, (R_xlen_t)1);
    INTEGER(ans)[0] = x;
    return ans;
}
//Rinternals.h
typedef int R_len_t;
