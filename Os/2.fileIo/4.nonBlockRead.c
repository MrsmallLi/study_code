/*************************************************************************
	> File Name: 4.nonBlockRead.c
	> Author: 
	> Mail: 
	> Created Time: Fri 17 May 2024 03:47:56 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main() {

    int fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        perror("Open /dev/tty");
        exit(1);
    }

    ssize_t n;
    char buff[20] = {0};
    while (1) {
        n = read(fd, buff, 10);
        if (~n) { 
            printf("read %ld bytes\n", n);
            write(STDOUT_FILENO, buff, n);
            putchar(10);
            break;
        }
        if (errno != EAGAIN) {
            perror("Read no gain");
            exit(1);
        }
        write(STDOUT_FILENO, "try try?\n", 9);
        sleep(1);
    }
    close(fd);
    return 0;
}

