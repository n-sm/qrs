#import <Foundation/Foundation.h>
#include "NSMLetra.m"
#include "NSNumberNSM.m"
#include "NSMFuncion.m"
#define SUMA @"suma"

int main (void)
{
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  NSLog(@"Hello");
  int i = 1;
  NSNumber *a = [NSNumber numberWithInteger: i];
  NSLog(@"numbero: %@", a.stringValue);
  NSArray *arr = [NSArray arrayWithObjects: a, nil];
  NSMFuncion *f1 = [[NSMFuncion alloc] initWithOper:SUMA
                                           yArgList:arr];
  NSNumber *n2 = [f1 car];
  NSLog(@"%@",[n2 asString]);
  [pool drain];
  return(0);
}
