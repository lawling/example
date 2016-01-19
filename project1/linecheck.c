#include<stdio.h>
#include<string.h>
#include<stddef.h>
int main(){
	int ch_cnt[1024] = {0};
	int line_cnt = 0,i = 0;
	char* c_ptr = NULL;
	char str[128][1024],c; 
	c_ptr = str[line_cnt];
	while(scanf("%c",&c) != EOF){
		*c_ptr = c;
		if(*c_ptr == '\n'){
			line_cnt++;
			c_ptr = str[line_cnt];
		}else{
			c_ptr++;
		}
	}

	for(i = 0; i < line_cnt ;i++){
		int cnt = 0;
		c_ptr = str[i];
		while( *c_ptr != '\n'){
			if(*c_ptr == '\t'){
				ptrdiff_t diff = c_ptr - str[i];
				int remainder = diff%8;
				cnt += 8 - remainder;                     
			}
			else cnt++;
			c_ptr++;
		} 
		ch_cnt[i] = cnt;
	}

	for(i = 0; i < line_cnt ; i++){
		printf("%4i: ",ch_cnt[i]);
		c_ptr = str[i];
		while(*c_ptr != '\n'){
			printf("%c",*c_ptr);
			c_ptr++;
		}
		printf("\n");   
	}
	return 0;
}
