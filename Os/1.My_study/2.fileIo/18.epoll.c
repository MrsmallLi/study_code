/*************************************************************************
	> File Name: 18.epoll.c
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Jul 2024 07:41:05 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>




int main() {
    int epoll_fd = epoll_create1(0);
    if (epoll_fd < 0) {
        perror("epoll_create1 error");
        exit(1);
    }

    struct epoll_event event;
    event.events = EPOLLIN;//监听可读事件
    event.data.fd = 0;//文件描述符设置为0，标准输入

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0, &event) < 0)  {
        perror("epoll_ctl error");
        close(epoll_fd);
        exit(1);
    }
    struct epoll_event events[1];
    int ret = epoll_wait(epoll_fd, events, 1, 5000);
    if (ret < 0) {
        perror("epoll_wait error");
        exit(1);
    }
    if (ret == 0) {
        fprintf(stderr, "Timeout epoll_wait Nothing\n");
        exit(1);
    }

    if (events[0].events & EPOLLIN) {
        char buff[100] = {0};
        ssize_t b_read = read(0, buff, sizeof(buff) - 1);
        if (b_read < 0) {
            perror("b_read error");
            exit(1);
        }
        printf("epoll sucess : %s", buff);
    }
    close(epoll_fd);
    return 0;
}
