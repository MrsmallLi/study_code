/*************************************************************************
	> File Name: 1.forkOpt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 04:23:59 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {

    char *msg;
    int n;
    pid_t child_pid = fork();
    if (child_pid < 0) {
        perror("fork");
        exit(1);
    }
    if (child_pid == 0) {
        n = 6;
        while (n > 0) {
            printf("child self = %d, parent = %d\n", getpid(), getppid());
            n--;
        }
    } else {
        n = 3;
        while (n > 0) {
            printf("parent self = %d, parent = %d\n", getpid(), getppid());
            n--;
        }
    }
    
    return 0;
}
