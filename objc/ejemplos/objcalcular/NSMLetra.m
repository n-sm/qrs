#import <Foundation/Foundation.h>
#include "NSMLetra.h"


@implementation NSMLetra
-(NSString*)name { return _name; }
-(void)setName:(NSString*)name { _name = name; }

-(id)initWithName:(NSString*)name{
  [self init];
  [self setName: name];
  return self;
}

-(NSString*)stringValue { return self.name ;}
-(NSMLetra*)simplificar { return self; }  
@end
