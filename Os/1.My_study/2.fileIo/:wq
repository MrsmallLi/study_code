/*************************************************************************
	> File Name: 16.select.c
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Jul 2024 06:35:27 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/select.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    fd_set refd;
    struct timeval timeout;
    int fd = 0;//标准输入流

    FD_ZERO(&refd);//初始化清空一下fd_set
    FD_SET(fd, &refd);//将标准输入流放入refd这个fd_set中

    //设置超时时间
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    int ret = select(fd + 1, &refd, NULL, NULL, &timeout);

    //说明没有文件
    if (ret == 0)  {
        fprintf(stderr, "Timeout Nothing");
        exit(1);
    }

    //发生错误
    if (ret < 0) {
        perror("select error");
        exit(2);
    }

    //开始对标准输入流读取
    char buff[100] = {0};
    ssize_t byt_read =  read(fd, buff, sizeof(buff) - 1);
    if (byt_read < 0) {
        perror("read error");
        exit(1);
    }
    printf("sucessful read : ");
    printf("%s", buff);
    return 0;
}
