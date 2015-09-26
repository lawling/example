#include<stdio.h>
struct tmp{
	int arr[2];
	int i;

}val;
int main(){
	int index = 0;


	val.arr[0] = 0;
	val.i = 0;

	printf("%p\t%p\t%p\n",&val.arr[0],&val.arr[1],&val.i);

	scanf("%d",&index);

	val.arr[index] = 100;

	printf("%d\t%d\t%p\n",index,val.arr[index],&val.arr[index]);

	printf("\nval.i = %i  %p\n",val.i,&val.i);
}
