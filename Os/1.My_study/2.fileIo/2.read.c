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
    if (argc < 2) {
        printf("usage : cmd + filename\n");
        return -1;
    }
    
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) {
        perror("Open error");
        exit(3);
    } else {
        printf("fd1 = %d\n", fd1);
    } 
   
    char buff[20] = {0};
    ssize_t n = read(fd1, buff, 10);
    printf("read %ld bytes\n", n);
    for (int i = 0; i < n; i++) {
        printf("%c", buff[i]);
    }
    printf("\n");

    n = read(fd1, buff, 10);
    printf("read %ld bytes\n", n);
    for (int i = 0; i < n; i++) {
        printf("%c", buff[i]);
    }
    printf("\n");

    close(fd1);
    return 0;
}
