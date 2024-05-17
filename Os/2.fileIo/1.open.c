/*************************************************************************
	> File Name: 1.open.c
	> Author: 
	> Mail: 
	> Created Time: Fri 17 May 2024 01:29:56 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("usage : cmd + filename\n");
        exit(-1);
    }

    int fd = open(argv[1], O_CREAT | O_RDONLY, 0644);
    if (fd < 0) {
        perror("open error");
        exit(1);
    } else {
        perror("open Sucess");
        exit(1);
    }
    return 0;
}
