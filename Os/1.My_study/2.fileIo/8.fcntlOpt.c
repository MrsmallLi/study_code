/*************************************************************************
	> File Name: 8.fcntlOpt.c
	> Author: 
	> Mail: 
	> Created Time: Fri 17 May 2024 04:59:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    int flags;    

    flags = fcntl(STDIN_FILENO, F_GETFL);
    if (flags < 0) {
        perror("fcntl get flags is error\n");
        exit(1);
    }
    flags |= O_NONBLOCK;
    flags = fcntl(STDIN_FILENO, F_SETFL, flags);
    if (flags < 0) {
        perror("fcntl set flags is error\n");
        exit(1);
    }
    
    char buff[20] = {0};
    ssize_t n;
    while (1) {
        n = read(STDIN_FILENO, buff, 5);
        if (n >= 0) break;
        if (errno != EAGAIN) {
            perror("read is error\n");
            exit(2);
        }
        sleep(1);
    }
    write(STDOUT_FILENO, buff, n);
    return 0;
}
