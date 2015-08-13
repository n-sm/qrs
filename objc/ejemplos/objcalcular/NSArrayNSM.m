#import "NSArrayNSM.h"

@implementation NSArray (NSM)
-(NSString*)stringValue{
  //  return [[self valueForKey:@"description"] componentsJoinedByString:@" "];
  NSMutableString *rmstr = [[NSMutableString alloc] init];
  for (id element in self) {
    [rmstr appendFormat:@"%@ ", [element stringValue]];
  }
  return rmstr;
}
@end
