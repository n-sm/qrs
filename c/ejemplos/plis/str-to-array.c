/*
  Esto lo escribi hace algun tiempo y lo traigo a este dir porque lo pienso usar en plis
  habria que hacerlo por lo tanto usando los nodos para armar "linked lists"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FORM_SZ 999

int strlng (char * str) {
  char * ptr = str;
  while (*ptr != '\0') ++ptr;
  return ( ptr - str );
}

char * cierrepar (char * str) {
  /*
    Esta función devuelve  un puntero hubicado en el paréntesis de cierre.
    si p == cierrepar(p) entonces no están balanceados los paréntesis.
    
  */

  int count = 1;
  int length = strlng(str) ;//sacar
  char * ptr = str;
  if ( *ptr != '(' ) {
    printf("La formula debe comenzar con parentesis.\n");
    return str;
  }
  do {
    ptr++;
    if ( *ptr == '(' ) ++count;
    if ( *ptr == ')' ) --count;
  } while ( *ptr != '\0' && count != 0 ) ;
  if (count != 0) {
    printf("No concuerdan los parentesis\n");
    return str;
      }
  else return ptr;
}

int countmembers (char * str) {
  int count = 0;
  char * ptr = str;
  if ( cierrepar(str) == str ) return -1; // no está bien la formula.
  ++ptr;
  while ( *ptr != '\0' ) {
    if (*ptr == ')') return count;
    if ( *ptr == ' ' ) while ( *ptr == ' ') ++ptr;
    else if ( *ptr == '(' ) {
      ++count;
      ptr = cierrepar(ptr) + 1 ;
    }
    else {
      ++count;
      while (*ptr != ' ' && *ptr != '\0' && *ptr != ')' ) ++ptr;
    }
  }
  return count;     
}

char* avanzarEspacios (char *str ) {

  char *p = str;

  while ( *p == ' ' ) ++p;
  return p;
}

char * proximoEspacio (char * str) {
  char *p = str;
  if ( *p == ' ' || *p == '\0' ) return str;
  else while ( *p != '\0' && *p != ' ' ) ++p;
  return p;
}

char * proximoDelimitador (char * str) {
  char *p = str;
  if ( *p == ' ' || *p == '\0' ) return str;
  else while ( *p != '\0' && *p != ' ' && *p != ')' ) ++p;
  return p;
}


char * nextElement (char *str) {

  char * p = str;
  p = proximoEspacio(p);
  p = avanzarEspacios(p);
  return p;
}

int strToArrayNoSubs (char * str, char * array[], char * cpstr) {
  /*
    El primer argumento de la función contiene la string a parsear.
    El segundo es el array donde se almacenrán sus elementos, el cual 
    deb crearse antes de llamar a la función y debe tener lugar para 
    cada elemento de la string a parsear (esto se puede hacer con:
    char * array[countmembers(str)];
    El tercerelemento es un pointer to char que resulta necesario para 
    copiar la string original (pues el array es una copia).
    
    El que llame a esta función debe luego ejecutar:
    free(cpstr);
   */
  if (str == cierrepar(str)) {
    printf("ERROR CON LOS PARENTESIS\n");
    return 0;
  }
  if ( *str != '(' ) {
    printf ("error, la string debe empezar con paréntesis\n");
    return 0;
  }

  cpstr =  malloc (strlen(str)+1);
  strcpy(cpstr,str);

  cpstr++; // avanzo el parentesis inicial.
  int length = countmembers(str);
  if ( length == 0 )    return 1;

  cpstr = avanzarEspacios(cpstr);

  array[0] = cpstr;

  int i;
  for ( i = 1 ; i < length ; ++i) {
    array[i] = nextElement(array[i-1]);
    //    char * tmp = array[i];
    //*(tmp-1) = '\0';
    *(array[i]-1) = '\0';
  }

  //  array[length-1] = proximoDelimitador(array[length-1]);
  //*array[length-1] = '\0';
  char * cerrador = array[length-1];
  cerrador  = proximoDelimitador(cerrador);
  *cerrador = '\0';
//while ( *tmp != ' ' &&  *tmp != ')' && *tmp != '\0') ++tmp;
  //  printf("debbuger:%c\n", *tmp);
  //*tmp = '\0';

  for ( i = 0 ; i < length ; ++i ) {
    printf ("\narray[%d] es:%s\n", i, array[i]);
  }

  return 1;
}

int strToArray (char * str, char * array[], char * cpstr) {
  /*
    El primer argumento de la función contiene la string a parsear.
    El segundo es el array donde se almacenrán sus elementos, el cual 
    deb crearse antes de llamar a la función y debe tener lugar para 
    cada elemento de la string a parsear (esto se puede hacer con:
    char * array[countmembers(str)];
    El tercerelemento es un pointer to char que resulta necesario para 
    copiar la string original (pues el array es una copia).
    
    El que llame a esta función debe luego ejecutar:
    free(cpstr);
   */
  // chequeo que este bien escrita:
  if (str == cierrepar(str)) { 
    printf("ERROR CON LOS PARENTESIS\n");
    return 0;
  }
  if ( *str != '(' ) {
    printf ("error, la formula debe empezar con paréntesis\n");
    return 0;
  }

  // hago una copia
  cpstr =  malloc (strlen(str)+1);
  strcpy(cpstr,str);

  // primer elemento:
  cpstr++; // avanzo el parentesis inicial.
  int length = countmembers(str);  
  if ( length == 0 )    return 1;
  cpstr = avanzarEspacios(cpstr);
  array[0] = cpstr; // 1er elemento.

  // resto de los elementos menos ultimo
  int i;
  for ( i = 1 ; i < length ; ++i) {
    array[i] = nextElement(array[i-1]);
    *(array[i]-1) = '\0';
    //    char * p = array[i];
    //*(tmp-1) = '\0';
    if ( *array[i] == '(' ) {
      //      printf("debu\n"); 
      array[i+1] = cierrepar(array[i]) + 1;
      ++i;
      array[i] = nextElement(array[i]);
      //      ++(array[i]);
      *(array[i]-1) = '\0';
    }
  }

  // //  array[length-1] = proximoDelimitador(array[length-1]);
  //  //*array[length-1] = '\0';
  // ultimo elemento:
  char * cerrador = array[length-1];
  if ( *cerrador == '(' ) {
    cerrador = cierrepar(cerrador) + 1;
    //    cerrador++;
  }
  else cerrador  = proximoDelimitador(cerrador);

  *cerrador = '\0';
//while ( *tmp != ' ' &&  *tmp != ')' && *tmp != '\0') ++tmp;
  //  printf("debbuger:%c\n", *tmp);
  //*tmp = '\0';

  for ( i = 0 ; i < length ; ++i ) {
    printf ("\narray[%d] es:%s\n", i, array[i]);
  }

  return 1;
}

void strToStrPtr (char * str, char ** strptr, char * cpstr) {
  /*
    El primer argumento de la función contiene la string a parsear.
    El segundo es el array donde se almacenrán sus elementos, el cual 
    deb crearse antes de llamar a la función y debe tener lugar para 
    cada elemento de la string a parsear (esto se puede hacer con:
    char * array[countmembers(str)];
    El tercerelemento es un pointer to char que resulta necesario para 
    copiar la string original (pues el array es una copia).
    
    El que llame a esta función debe luego ejecutar:
    free(cpstr);
   */
  if (str == cierrepar(str)) {
    printf("ERROR CON LOS PARENTESIS\n");
    return;
  }
  //cpstr =  malloc (strlen(str)+1);
  strcpy(cpstr,str);
  if ( *str != '(' ) {
    printf ("error, la string debe empezar con paréntesis\nexit");
    return;
  }
  cpstr++;

  int length = countmembers(str);
  char * array[length];
  array[0] = nextElement(cpstr);
  
  int i;
  for ( i = 1 ; i < length ; ++i) {
    array[i] = nextElement(array[i-1]);
    char * tmp = array[i];
    *(tmp-1) = '\0';
  }
  char * tmp = array[length-1];
  while ( *tmp != ' ' &&  *tmp != ')' && *tmp != '\0') ++tmp;
  printf("debbuger:%c\n", *tmp);
  *tmp = '\0';
  for ( i = 0 ; i < length ; ++i ) {
    printf ("\narray[%d] es:%s\n", i, array[i]);
  }
  strptr = array;
  return;
}


int main (void) {
  char *formula = malloc (MAX_FORM_SZ);
  if (formula == NULL) {
    printf ("No memory\n");
    return 1;
  }
  printf("Escriba la formula:\n");
  fgets (formula, MAX_FORM_SZ, stdin);
  /* Remove trailing newline, if there. */
  if ((strlng(formula)>0) && (formula[strlng (formula) - 1] == '\n'))
    formula[strlng (formula) - 1] = '\0';
  int mem = countmembers(formula);
  if (mem > -1) printf("La formula:\"%s\" tiene %d miembro(s).\n", formula, mem);

  //  int leng = count
  char ** strptr;
  char * cpstr =  malloc (strlen(formula)+1);
  char * arr[mem];
  printf("mem: %d\n",mem);
  int test;
  test = strToArray(formula, arr, cpstr) ;
  if (test == 0) return 1;

  printf("ahora salgo de strToArray\n");
  
/*  int i;
  for ( i = 0; i < mem; ++i ) {
    printf("arr[%d]: %s\n length: %d\n", i, arr[i], (int) strlen(arr[i]));
  }
*/
  

  free(cpstr);
  free(formula);
  return 0;
}
