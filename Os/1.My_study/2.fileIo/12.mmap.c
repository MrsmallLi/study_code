/*************************************************************************
	> File Name: 12.mmap.c
	> Author: 
	> Mail: 
	> Created Time: Sun 19 May 2024 06:22:50 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>


int main() {

    int fd = open("./text.txt", O_RDWR);
    if (fd < 0) {
        perror("open error");
        exit(1);
    }

    int *p = (int *)mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
    p[0] = 0x30313232;
    munmap(p, 6);
    return 0;
}
