/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Jul 2024 06:41:43 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define SERV_PORT 8000
#define MAXLINE 80


int main() {

    struct sockaddr_in serveraddr, cliaddr;
    int listenfd, connfd, n;
    
    char buff[MAXLINE];
    char str[INET_ADDRSTRLEN];

    
    socklen_t cliaddr_len;
    
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    //服务器 ip地址： 端口初始化
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERV_PORT);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(listenfd, (struct sockaddr *)(&serveraddr), sizeof(serveraddr));

    listen(listenfd, 3);
    printf("Acceptin connections..\n");
    while (1) {
        cliaddr_len = sizeof(cliaddr);
        connfd =  accept(listenfd, (struct sockaddr *)(&cliaddr), &cliaddr_len);

        printf("received from %s : %d\n", 
               inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), 
               ntohs(cliaddr.sin_port)
              );

        n = read(connfd, buff, MAXLINE);

        for (int i = 0; i < n; i++) {
            buff[i] = toupper(buff[i]);
        }
        
        write(connfd, buff, n);
        close(connfd);
    }
    
    return 0;
}
