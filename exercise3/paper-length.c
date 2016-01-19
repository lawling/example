#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
   pid_t pid;
   int fd[2];
   pipe(fd);

   pid = fork();

   if(pid == 0){
      dup2(fd[1],STDOUT_FILENO);
      execlp("wc","wc","-w",NULL);
      close(fd[0]);
   }else{
      int str;
      dup2(fd[0],STDIN_FILENO);
      scanf("%d",&str);

      if(str >=  200){
	 printf("Long enough!\n");
}
      else  {   
	 printf("Too short!\n"); 
         exit(1);
}
      close(fd[1]);
   }



   return 0;
}
