#include<stdlib.h>
#include<stdio.h>
int main(){
int i,j,k,l,m,n;
int *p;
for(i = 0; i < 1000 ;i++)
	for(j = 0; j < 1000 ; j++)
		for(k = 0; k <1000;k++)
			for(l = 0; l < 1000;l++)
				p = malloc(sizeof(int));
printf("done\n");
}
