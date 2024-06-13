/*************************************************************************
	> File Name: 14.errno.c
	> Author: 
	> Mail: 
	> Created Time: Sun 26 May 2024 04:43:01 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


int main() {
    const char *msg = "Hello, errno!\n";
    //printf
    printf("Before system call : errno is %d\n", errno);
    ssize_t wsize = write(3, msg, strlen(msg));
    if (wsize < 0) {
        printf("After system call : errno is %d\n", errno);
        perror("write error");
    }
    return 0;
}
