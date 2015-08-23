#import <Foundation/Foundation.h>

@protocol Eater
@required
- (void) eat;
@optional
- (void) belch;
@end

@interface Glutton : NSObject <Eater> {
}
@end
@implementation Glutton
- (void) eat {
	NSLog(@"Glutton eating...");
}

- (void) belch {
	NSLog(@"Glutton belchin...");
}
@end

@interface Glutton : NSObject <Eater> {
}
@end
@implementation Socialite
- (void) eat {
	NSLog(@"Socialite eating...");
}

- (void) belch {
	NSLog(@"Socialite belchin...");
}
@end

int main (int argc, const char * argv []) {
	NSAutoreleasePool * Pool = [[NSAutoreleasePool alloc] init];
	Glutton * myGlutton = [[[Glutton alloc] init] autorelease];
	Socialite * mySocialite = [[[Socialite alloc] init] autorelease];
	[myGlutton eat];
	[mySocialite eat];
	[myGlutton belch];
	if([mySocialite respondsToSelector:@selector(belch)]){
		[mySocialite belch];
	}
	[pool drain];
	return 0;
}
