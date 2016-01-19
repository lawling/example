#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct sockaddr SA;
int 
main()
{
   int	listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

   struct sockaddr_in servaddr, cliaddr;

   bzero(&servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(8080);
   servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

   bind(listenfd, (SA*) &servaddr, sizeof(servaddr));

   listen(listenfd, 0);

   for (;;) {
      socklen_t len = sizeof(cliaddr);
      int connfd = accept(listenfd,(SA *) &cliaddr, &len);

      printf("connection begins \n");

      const char * s = "you get connected\n"
	               "write what you want to post\n";

      buf[1024];
      write(connfd, s, strlen(s));
      read(connfd,buf,strlen(buf);

	    //append buf to index html
      close(connfd);
   }
   return 0;
}
