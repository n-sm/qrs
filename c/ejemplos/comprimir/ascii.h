#define ES_LETRA(X)				\
  ('A' <= (X) && 'Z' <= (X)) ||   ('a' <= (X) && 'z' <= (X))

#define ES_NUMERO(X)				\
  ('0' <= (X) '9')

#define ES_ESPACIO(X)				\
  ((X) == ' ' || (X) == '\t' || (X) == '\n')
  
  
