#import<Foundation/Foundation.h>
int main(){
NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
NSLog (@"Hello World");
[pool drain];
return 0;
}
