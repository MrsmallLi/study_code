/*************************************************************************
	> File Name: 2.read.c
	> Author: 
	> Mail: 
	> Created Time: Fri 17 May 2024 03:03:45 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char buff[20] = {0};
    ssize_t n;
    n = read(STDIN_FILENO, buff, 10);
    if (n < 0) {
        perror("Read STDIN");
        exit(1);
    }
    printf("read %ld bytes\n", n);

    write(STDOUT_FILENO, buff, n);
    write(STDOUT_FILENO, "\n", 1);
    return 0;
}
