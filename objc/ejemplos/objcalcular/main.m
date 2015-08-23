#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#import <Foundation/Foundation.h>
#include "NSMLetra.m"
#include "NSNumberNSM.m"
#include "NSArrayNSM.m"
#include "NSMFuncion.m"
#import "constantes.h"
#define MAX_FORM_SZ 999

int main (void)
{
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  printf("=====\n");
  /*
  int i = 1;
  NSNumber *a = [NSNumber numberWithInteger: i];
  NSNumber *b = [NSNumber numberWithInteger: 2];
  NSMLetra *x = [[NSMLetra alloc] initWithName:@"x"];
  NSMLetra *y = [[NSMLetra alloc] initWithName:@"y"];
  NSMLetra *z = [[NSMLetra alloc] initWithName:@"z"];
  NSMLetra *w = [[NSMLetra alloc] initWithName:@"w"];
  NSArray *arr = [NSArray arrayWithObjects: a,b,x,y,z,w,x,x,x,nil];
  //// creo funcion
  NSMFuncion *f1 = [[NSMFuncion alloc] initWithOper:SUMA
                                           yArgList:arr];
  NSNumber *n2 = [f1 car];
  NSLog(@"Este es (car f1): %@",n2.stringValue);
  NSString *nsstr = f1.stringValue;
  NSLog(@"NSLog de nsstr: %@",nsstr);
  //  char * cstring = [f1 cString];
  printf("aca lo nuevo:\n");
  
  NSLog(@"parte numerica de f1: %@", [[f1 parteNumerica] stringValue]);
  NSLog(@"arr.stringValue: %@",[arr stringValue]);
  NSLog(@"f1.letras stringValue: %@",[[f1 letras] stringValue]);
  
  
  NSNumber *ocu = [f1 ocurrenciasDe:x];


  
  NSLog(@"ocurrencias de x en f1: %@",ocu);
  */
  char *formula = malloc (MAX_FORM_SZ);
  if (formula == NULL) {
    printf ("No memory\n");
    return 1;
  }

  printf("Escriba la formula:\n");

  fgets (formula, MAX_FORM_SZ, stdin);

  /* Remove trailing newline, if there. */
  if ((strlen(formula)>0) && (formula[strlen (formula) - 1] == '\n'))
    formula[strlen (formula) - 1] = '\0';

  printf("La formula es:\n%s\n", formula);

  NSString *nsformula = [[NSString alloc] initWithCString:formula encoding:1];
  free (formula);

  NSLog(nsformula);



  [pool drain];


  return(0);
}
