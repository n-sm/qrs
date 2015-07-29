# http://stackoverflow.com/questions/31617804/rccp-quicksort-error-in-r

incl <- 'int quicksort(int xx[], int left, int right) {

int i = left;
int j = right;
int tmp;
int pivot = xx[(left + right) / 2];

/* partition */
while (i <= j) {
while (xx[i] < pivot)
i++;
while (xx[j] > pivot)
j--;
if (i <= j) {
tmp = xx[i];
xx[i] = xx[j];
xx[j] = tmp;
i++;
j--;
}
}

/* recursion */
if (left < j){
quicksort(xx, left, j);
}
if (i < right){
quicksort(xx, i, right);
}

return (quicksort(xx,i,j));
}
'
sortCpp <- cxxfunction(signature( x = "integer",left = "integer",
                                  right = "integer"),
                       body = 'IntegerVector arr(x);
                       int a = as<int>(left);
                       int b = as<int>(right);
                       return wrap(quicksort(arr,a,b));',
                       include = incl,
                       plugin = "Rcpp",
                       verbose = TRUE)

incl2 <- 'int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
'


factcpp <- cxxfunction(signature( x = "integer"),
                       plugin = "Rcpp",
                       include = incl2,
                       body = 'int xnew = as<int>(x);
                       return wrap( factorial(x) );
                       ',
                       verbose = TRUE)
