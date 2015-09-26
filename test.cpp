#include<stdio.h>
void foo( int * arr){
//printf("size of arr is %lu",sizeof(arr));
(*arr)++;
printf("%i\n",*arr);
}
int main(){
const int i = 10;
foo(&i);
//printf("size of arr out side of function is %lu\n",sizeof(i));
foo(&i);


}
