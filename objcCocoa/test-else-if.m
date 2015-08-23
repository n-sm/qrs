#import <Foundation/Foundation.h>

int main (int argc, const char * argv[])
{
      NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

      int value;

      printf ("Enter a number between 0 and 5: ");

      scanf ("%i", &value);

      if (value == 0)
        NSLog (@"zero");
      else if (value == 1)
        NSLog (@"one");
      else if (value == 2)
        NSLog (@"two");
      else if (value == 3)
        NSLog (@"three");
      else if (value == 4)
        NSLog (@"four");
      else if (value == 5)
        NSLog (@"five");
      else
        NSLog (@"Integer out of range");

      [pool drain];
      return 0;
}
