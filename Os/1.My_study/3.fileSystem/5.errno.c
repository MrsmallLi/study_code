/*************************************************************************
	> File Name: 5.errno.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 May 2024 03:19:48 PM CST
 ************************************************************************/

#include <stdio.h> 
#include <string.h>
#include <unistd.h>


int main() {
    const char *msg = "Hello, errno!";
    ssize_t wsize = write(1, msg, strlen(msg));
    printf("errno is %d%s")
    if (wsize == -1) {

    }
    return 0;
}
