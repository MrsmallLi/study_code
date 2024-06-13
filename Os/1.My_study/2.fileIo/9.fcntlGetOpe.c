/*************************************************************************
	> File Name: 9.fcntlGetOpe.c
	> Author: 
	> Mail: 
	> Created Time: Fri 17 May 2024 05:10:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("usage : cmd + fd\n");
        exit(1);
    }
    
    int flags = fcntl(atoi(argv[1]), F_GETFL);
    if (flags < 0) {
        perror("fcntl get flags is error\n");
        exit(1);
    }
    /*
    printf("flags = %#x\n", flags);
    printf("O_RDONLY = %#x\n", O_RDONLY);
    printf("O_WRONLY = %#x\n", O_WRONLY);
    printf("O_RDWR = %#x\n", O_RDWR);
    printf("O_APPEND = %#x\n", O_APPEND);
    printf("O_NONBLOCK = %#x\n", O_NONBLOCK);
    printf("O_ACCMODE = %#x\n", O_ACCMODE);
    */
    return 0;
}
