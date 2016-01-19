#include <stdio.h>
long gcd(long a , long b){
long r = a % b;
if( r == 0)
   return b;

return gcd(b, r);

}

int main(){
printf("prime of 25 and 15 is %ld\n",gcd(25,15) );

}
