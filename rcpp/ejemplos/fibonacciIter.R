fileName <- 'fibonacciIter.cpp'
fibonacciIter <- cxxfunction(signature(xs="int"),
                             plugin="Rcpp",
                             body=readChar(fileName, file.info(fileName)$size))
