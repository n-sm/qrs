fileName <- 'test.cpp'
testf <- cxxfunction(signature(xs="int"),
                             plugin="Rcpp",
                             body=readChar(fileName, file.info(fileName)$size))
