#import "NSMFuncion.h"

@implementation NSMFuncion

- (id)init {
  self = [super init];
  if(self){
    [self setOper: nil];
    //    _argumentos = [[NSArray alloc] init];
  }
  return self;
}
-(id)initWithOper:(NSString*) operacion yArgList:(NSArray*) args {
  [self init];
  [self setOper: operacion];
  [self setArgs: args];
  return self;
}
-(NSString*)oper{
  return _operacion;
}
-(void)setOper:(NSString*)arg{
  _operacion = arg;
}
-(NSArray*)args{
  return _argumentos;
}
-(void)setArgs:(NSArray*) arg{
  _argumentos = arg;
}

-(id)car{
  return [self.args objectAtIndex:0];
}

-(id)simplificar{
  NSMFuncion *retFunc = [[NSMFuncion alloc] init];
  [retFunc setOper:SUMA];
  NSMutableArray *retArray;

  return self;
}
@end




/*-(id)simplificarSumaUn{
  //acá hay un único argumento, un átomo, y es suma. ej: suma(1).
  return [self.args objectAtIndex:0];
}
  
-(id)simplificarSumaBinAtoms{
  // acá los args=2 y cada uno es NSNumber o NSMVar.
  // primer condicion, los dos son números.
  if ([[self.args objectAtIndex:0] isMemberOfClass:[NSNumber class]] &&
      [[self.args objectAtIndex:1] isMemberOfClass:[NSNumber class]]) {
    double i, j;
    i = [[self.args objectAtIndex:0] doubleValue];
    j = [[self.args objectAtIndex:1] doubleValue];
    NSNumber* suma = [NSNumber numberWithDouble: i + j];
    return [[NSMFormula alloc] initWithOperacion: NINGUNA
					   yArgs: [NSArray arrayWithObject: suma]];
    }
  //segunda condicion, dos variables iguales
  else if ([[primero.args objectAtIndex:0] isMemberOfClass:[NSMVar class]] &&
	   [[segundo.args objectAtIndex:0] isMemberOfClass:[NSMVar class]]) {
    if([[[primero.args objectAtIndex:0] stringValue] isEqualTo:[[segundo.args objectAtIndex:0] stringValue]]) {
      NSNumber *number = [[NSNumber alloc] initWithDouble:2];
      NSArray *args = [NSArray arrayWithObjects: number, [self.args objectAtIndex:0], nil];
      NSMFormula *retForm = [[NSMFormula alloc] initWithOperacion: PROD
							    yArgs: args];
      return retForm;
    }
  }
  //en otro caso no hacer nada.
  else return self;
}

-(id)simplificarSumaBin{
  // Acá args=2 y hay algun arg no atom.
  // creo fórmula para return.
  NSMFormula *retForm = [[NSMFromula alloc] init];
  
    else if ([[primero.args objectAtIndex:0] isMemberOfClass:[NSNumber class]] &&
	     [[segundo.args objectAtIndex:0] isMemberOfClass:[NSNumber class]]) {
      double i, j;
      i = [[primero.args objectAtIndex:0] doubleValue];
      j = [[segundo.args objectAtIndex:1] doubleValue];
      NSNumber* suma = [NSNumber numberWithDouble: i + j];
      NSArray *sumaArr = [NSArray arrayWithObject:suma];
      return [[NSMFormula alloc] initWithOperacion: NINGUNA
					    yArgs: [NSArray arrayWithObject: sumaArr]];
    } // ambos elementos de la fórmula son variables.
    else if ([[primero.args objectAtIndex:0] isMemberOfClass:[NSMVar class]] &&
	     [[segundo.args objectAtIndex:0] isMemberOfClass:[NSMVar class]] &&
	     [[[primero.args objectAtIndex:0] stringValue] isEqualTo:[[segundo.args objectAtIndex:0] stringValue]]) {
      NSNumber *number = [[NSNumber alloc] initWithDouble:2];
      NSArray *lista = [NSArray arrayWithObjects: number, [primero.args objectAtIndex:0], nil];
      NSMFormula *retForm = [[NSMFormula alloc] initWithOperacion: PROD
							   yArgs: lista];
      return retForm;
    } // acá puede ocurrir que haya un número y una variable o alguna subfórmula.
    else {
      NSArray *primerSumando = [[NSArray alloc] init];
      NSArray *segundoSumando = [[NSArray alloc] init];
      // el primer miembro es fórmula
      if([[self.args objectAtIndex:0] isMemberOfClass: [NSMFormula class]]) {
	//simplifico primer miembro y saco su lista.
	primerSumando = [[[self.args objectAtIndex:0] simplificar] args];
      }
      // si no el primer miembro no cambia
      else primerSumando = [self.args objectAtIndex:1];
      // el segundo miembro es fórmula
      if([[self.args objectAtIndex:1] isMemberOfClass: [NSMFormula class]]) {
	//simplifico segundo  miembro
	primerSumando = [[[self.args objectAtIndex:1] simplificar] args];
      }
      // si no el primer miembro no cambia
      else primerSumando = [self.args objectAtIndex:1];
      NSArray *retList = [NSArray arrayWithObjects: primerSumando,
				  segundoSumando, nil];
      return [[NSMFormula alloc] initWithOperacion:SUMA
					    yArgs:retList];
    }
  }
    else return self;
}      

-(id)simplificar{
  return [self simplificarSuma];
}
-(id)simplificarSuma{
  if([SUMA isEqualToString: self.operacion]) {
    if ([[self args] count] == 1) return self;
    else {
      if([[self args] count] == 2) {
	return [self simplificarSumaBin];
      }
      else {
	return self;
      }
    }
  }
    else return self;
}


-(NSString*)asStringSuma{
  int contador = 0;
  NSMutableString *retString = [[NSMutableString alloc] init];
  [retString appendString:@"("];
  //  NSArray *copia = self;
  for(id elemento in [self args]){
    [retString appendString: [elemento stringValue]];
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
*/
