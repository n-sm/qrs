int n = Rcpp::as<int>(xs);
double first = 0;
double second = 1;
double third = 0;
for (int i=0; i<n; i++) {
  third = first + second;
  first = second;
  second = third;
 }
return Rcpp::wrap(first);
