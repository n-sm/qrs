//<--Objc-->
#import <Foundation/Foundation.h>

@interface NSMLetra : NSObject {
  NSString *_name;
}
-(NSString*)name;
-(void)setName:(NSString*)name;
-(id)initWithName:(NSString*)name;
-(NSString*)stringValue;
-(NSMLetra*)simplificar;
@end
