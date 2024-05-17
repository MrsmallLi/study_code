/*************************************************************************
	> File Name: 7.lseekOpt.c
	> Author: 
	> Mail: 
	> Created Time: Fri 17 May 2024 04:41:01 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("argments : cmd + filename");
        exit(1);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open error");
        exit(2);
    }

    char c;
    read(fd, &c, 1);
    write(STDOUT_FILENO, &c, 1);
    lseek(fd, 3, SEEK_SET);
    putchar(10);

    read(fd, &c, 1);
    write(STDOUT_FILENO, &c, 1);
    putchar(10);

    close(fd);
    return 0;
}
