// -*-ObjC-*-
// también puede hacerse usando:
// extern NSString * const suma;
// junto con:
// NSString * const  = @"suma";

#import <Foundation/Foundation.h>

#define SUMA @"suma"
#define RESTA @"resta"
#define PROD @"prod"
#define DIV @"div"
#define POT @"pot"
#define RAIZ @"raiz"
#define LOG @"log"
#define NINGUNA @"ninguna"

NSArray* strToArray(char* str){
  // esta función la dejamos para después
  NSArray *retArray =  [[NSArray alloc] init];
  return retArray;
}
  
@interface NSMVar : NSObject {
  NSString *_name;
}
-(NSString*)name;
-(void)setName:(NSString*)name;
-(id)initWithName:(NSString*)name;
-(NSString*)stringValue;
//-(BOOL)isEqualTo:(NSMVar*)var;
@end

@implementation NSMVar
-(NSString*)name { return _name; }
-(void)setName:(NSString*)name { _name = name; }
-(id)initWithName:(NSString*)name{
  [self init];
  [self setName: name];
  return self;
}
-(NSString*)stringValue { return self.name ;}
//-(BOOL)isEqualTo:(NSMVar*)var{
  
@end

@interface NSMFormula : NSObject {
  NSString *_operacion;
  NSArray *_argumentos;
}
-(id)init;
-(id)initWithOperacion:(NSString*) operacion yArgs:(NSArray*) args;
-(NSString*)operacion;
-(void)setOperacion:(NSString*) arg;
-(NSArray*)args;
-(void)setArgs:(NSArray*) arg;
-(id)simplificarSumaUn;
-(NSString*)asStringSuma;
-(NSString*)asStringProd;
-(NSString*)asString;
@end

@implementation NSMFormula

- (id)init {
  self = [super init];
  if(self){
    _operacion = NINGUNA;
    //    _argumentos = [[NSArray alloc] init];
  }
  return self;
}
-(id)initWithOperacion:(NSString*) operacion yArgs:(NSArray*) args {
  [self init];
  [self setOperacion: operacion];
  [self setArgs: args];
  return self;
}
-(NSString*)operacion{
  return _operacion;
}
-(void)setOperacion:(NSString*)arg{
  _operacion = arg;
}
-(NSArray*)args{
  return _argumentos;
}
-(void)setArgs:(NSArray*) arg{
  _argumentos = arg;
}

-(id)simplificarSumaUn{
  //acá hay un único argumento, un átomo, y es suma. ej: suma(1).
  return [self.args objectAtIndex:0];
}
  


-(NSString*)asStringSuma{
  int contador = 0;
  NSMutableString *retString = [[NSMutableString alloc] init];
  [retString appendString:@"("];
  //  NSArray *copia = self;
  for(id elemento in [self args]){
    //    NSLog(@"ahora estoy en el loop...");
    if([elemento isMemberOfClass: [NSNumber class]])  [retString appendString: [elemento stringValue]];
    //    NSLog(@"ahora estoy en el loop...2");
    if(++contador < (int) [[self args] count] ){
      [retString appendString: @" + "];}
    else {[retString appendString: @")"];}
  }
  return (NSString*)retString;
}

-(NSString*)asStringProd{
  //  int contador = 0;
  NSMutableString *retString = [[NSMutableString alloc] init];
  [retString appendString:@"("];
  //  NSArray *copia = self;
  for(id elemento in [self args]){
    [retString appendString: [elemento stringValue]];
    //  if(++contador < (int) [[self args] count] ){
    //  [retString appendString: @" + "];}
  }
  [retString appendString: @")"];
  return (NSString*)retString;
}

-(NSString*)asString{
  if([self.operacion isEqualToString: SUMA]) return [self asStringSuma];
  else return [self asStringProd];
}
@end


int main (int argc, const char * argv[])
{
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

  NSNumber *a = [[NSNumber alloc] initWithDouble:1];
  NSNumber *b = [NSNumber numberWithDouble:2];
  NSArray *laArray = [NSArray arrayWithObjects: a, b, nil];
  NSMFormula *form1 = [[NSMFormula alloc] initWithOperacion: SUMA
						      yArgs: [NSArray arrayWithObject: laArray]];

  printf("\n\n::1::\n");
  NSLog([form1 asString]);
  //  printf("La formula inicial es: %s\n", [form1.asString UTF8String]);

  [pool drain];
  return 0;
}
