## http://stackoverflow.com/questions/31617804/rcpp-quicksort-error-in-r
## funciona en linux.
src <- 'Rcpp::IntegerVector v = Rcpp::IntegerVector(vp);
        std::sort(v.begin(), v.end());
        return wrap(v);'

fun <- cxxfunction(signature(vp="integer"), body=src, plugin="Rcpp")

fun( c(5, 2, 7, -3) )

