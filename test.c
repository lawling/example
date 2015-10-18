#include <stdio.h>
typedef struct data{
char c;
long arr;
int i;
}data;	
int main(){
int arr_3[10][10][10];
printf("%p\t%p\t%p\n",arr_3,*arr_3,**arr_3);
printf("size of float is %lu\n",sizeof(float));
data d;
printf("sizeof data is %lu\n",sizeof(d));
data arr[2];
printf("index 0 address is %p index address 1 is %p",&arr[0],&arr[1]);
return 0;
}
