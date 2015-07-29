int n = Rcpp::as<int>(xs);

return Rcpp::wrap(n);

int sucesor(int x) {
  return x + 1;
}

