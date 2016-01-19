#include<stdio.h>
int main(){
int i;
printf("CC := gcc\n"
       "FLAGS := -ansi -pedantic-errors -Wall -Werror -Wshadow -Wwrite-strings \n"
       "HEADERS := split.h sss.h sss-implementation.h\n"
       "OBJS := sss.o split.o memory-checking.o\n");

printf("all:");

for(i = 1; i < 11;i++){
   if( i == 6){
     printf("\\\n");
  }
   printf("public%02d.x ",i);
}

printf("\n");

for( i = 1; i < 11;i++){
   printf("public%02d.x: public%02d.o $(HEADERS) $(OBJS)\n"
          "\t$(CC) $(FLAGS) public%02d.o" 
          " $(OBJS) -o public%02d.x \n",i,i,i,i);


   printf("public%02d.o:public%02d.c $(HEADERS)\n"
         "\t$(CC) $(FLAGS) -c public%02d.c\n\n",i,i,i);
  }


printf("sss.o:sss.c $(HEADERS)\n"
       "\t$(CC) $(FLAGS) -c sss.c\n");

printf("clean:\n"
       "\trm public??.o\n"
       "\trm public??.x\n"
       "\trm sss.o\n"
       );
  return 0;
}
