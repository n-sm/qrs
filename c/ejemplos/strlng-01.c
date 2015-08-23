
int strlng (char * str) {
  char * ptr = str;
  while (*ptr != '\0') ++ptr;
  return ( ptr - str );
}
