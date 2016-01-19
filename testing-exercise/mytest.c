#include"./my-string.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
char* rand_str(int len){
   time_t t;
   int i;
   char*str = malloc(sizeof(char)*(len+1));
   srand((unsigned) time(&t));
   for(i = 0; i < len;i++){
      str[i] = rand()%128;

   }
   return str;

}
void clear_str(char* s){
   free(s);
}
int main(){
   time_t t;
   int i;
   char*rstr;
   My_string* s_ptr;
   My_string str[101];
   srand((unsigned)time(&t));
   for(i = 0 ; i < 100;i++){
      init(&str[i]);
      init(&str[i+1]);
      s_ptr = &str[i];
      rstr = rand_str(i);
      assign(s_ptr,rstr);
      assign(s_ptr+1,rstr);
      if(equal(str[i],str[i+1])==1)
        printf("pass\n");
       else printf("fail\n");
      clear_str(rstr);
      clear(&str[i]);
      clear(&str[i+1]);
   }


   return 0;
}
