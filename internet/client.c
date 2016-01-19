#include <stdio.h>
#include <unistd.h>
#include<sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
typedef struct sockaddr SA;

int main(int argc, char** argv){
    if ( argc != 2){
	printf("incorrect input \n");
	return 0;
    }

    int sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    struct sockaddr_in servaddr;

    bzero(&servaddr, sizeof(servaddr) );
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    inet_pton(AF_INET, argv[1],&servaddr.sin_addr);

    connect(sockfd,(SA*)&servaddr,sizeof(servaddr) );
    printf("connect begins\n");
    char buff[1024];
    read(sockfd,buff,1024);

    printf("%s",buff);
    scanf("%s",buff);
    write(sockfd,buff,1024);
    return 0;

}
