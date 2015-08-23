#import <Foundation/Foundation.h>
#import "constantes.h"

@interface NSMFuncion : NSObject {
  NSString *_operacion;
  NSArray *_argumentos;
}
-(id)init;
-(id)initWithOper:(NSString*) operacion yArgList:(NSArray*) args;
-(NSString*)oper;
-(void)setOper:(NSString*) arg;
-(NSArray*)args;
-(void)setArgs:(NSArray*) arg;
-(id)car;
-(NSInteger*)count;
-(NSNumber*)ocurrenciasDe:(id) objeto;
-(id)simplificar;
-(id)simplificarSuma;
-(NSString*)stringValue;
//-(char*)cString;
@end




/*-(id)simplificarSumaBin;
-(id)simplificarSuma;

-(NSString*)asStringSuma;
-(NSString*)asStringProd;
-(NSString*)asString;
*/

