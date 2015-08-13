#include <stdio.h>
#include <Foundation/Foundation.h>

@interface Test {
  NSString *primerNSString;
}
- (id)init;
- (NSString *) getter;
+ (const char *) classStringValue;

@end

@implementation Test
+ (const char *) classStringValue;
{
  return "This is the string value of the string class";
}

- (id)init;{
  primerNSString = @"usando init";
  return self;
}

- (NSString *) getter;{
  return primerNSString;
}

@end

int main(void)
{
  //  Test *testInstance;
  printf("\n%s\njeje\n", [Test classStringValue]);
  NSLog(@"una NSString");
  return 0;
}
