#include <stdio.h>
#include <Foundation/Foundation.h>

@interface unaClase : NSObject
{
  NSString *_primerNSString;
}

- (id) init;
- (NSString *) primerNSString;
- (void) setPrimerNSString:(NSString *) string;
@end

@implementation unaClase
- (id) init 
{
  self = [super init];
  if(self) {
  _primerNSString = @"Contenido de primera NSStrin creado en init";
  }
  return self;
}

- (NSString *) primerNSString {
  return _primerNSString;
}
 - (void) setPrimerNSString:(NSString *) string {
  _primerNSString = string;
 }
@end

int main(void)
{
  unaClase *instanciaDeUnaClase = [[unaClase alloc ] init];
  NSString *nuevaNSS = [[NSString alloc] initWithString:@"esta es una string"];
  printf("%s\n", [nuevaNSS UTF8String]);
  printf("%s\n", [[instanciaDeUnaClase primerNSString] UTF8String]);
  return 0;
}
