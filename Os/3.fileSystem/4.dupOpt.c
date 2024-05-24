/*************************************************************************
	> File Name: 4.dupOpt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 20 May 2024 05:31:56 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


int main() {
    
    int fd, save_fd;
    fd = open("test.txt", O_RDWR);
    if (fd < 0) {
        perror("open error");
        exit(1);
    }

    save_fd = dup(1);
    dup2(fd, 1);
    close(fd);
    write(1, "1234567890", 10);
    dup2(save_fd, 1);
    write(1, "1234567890", 10);
    close(save_fd);
    return 0;
}
