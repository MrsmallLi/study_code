/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Jul 2024 07:12:41 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define SERV_PORT 8000
#define MAXLINE 80


int main() {
    
    struct sockaddr_in serveraddr;
    char buff[MAXLINE] = {"hello tcp"};

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET; 
    serveraddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr);

    connect(sockfd, (struct sockaddr *)(&serveraddr), sizeof(serveraddr));
    
    write(sockfd, buff, strlen(buff));
    
    int n = read(sockfd, buff, MAXLINE);
    
    printf("response from server : \n");

    write (1, buff, n);
    while (1) sleep(1);

    close(sockfd);
    return 0;
}
