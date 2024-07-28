/*************************************************************************
	> File Name: 17.poll.c
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Jul 2024 07:26:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <poll.h>
#include <stdlib.h>
#include <unistd.h>



int main(){
    struct pollfd fds[1];
    int fd = 0;//还是监听标准输入流

    fds[0].fd = fd;
    fds[0].events = POLLIN; 

    //监视fds集合，集合中只有一个文件描述符,等但时间为5000ms
    int ret = poll(fds, 1, 5000);

    //发生错误 
    if (ret == -1)  {
        perror("poll error");
    }

    if (ret == 0) {
        fprintf(stderr, "poll Nothing\n");
        exit(1);
    }

    //与上它为真说明发生的事件就是这个
    if (fds[0].revents & POLLIN)  {
        char buff[100] = {0};
        ssize_t byt_read = read(fd, buff, sizeof(buff) - 1);
        if (byt_read < 0) {
            perror("read error");
            exit(1);
        }
        printf("poll sucess : %s", buff);
    }
    return 0;
}
