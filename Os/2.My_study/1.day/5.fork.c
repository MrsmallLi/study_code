/*************************************************************************
	> File Name: 5.fork.c
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Jun 2024 07:14:34 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>



int main() {
    printf("Hello world");
    pid_t pid = 0;
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        printf("I am child\n");
    } else {
        printf("I am parent\n");
    }
    return 0;
}
