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
    
    
    for (int i = 0; i < 10; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);
        }
        if (!pid) {
            printf("child[%d], self = %d, parent = %d\n", i, getpid(), getppid());
            sleep(1);
            break;
        }
    }
    return 0;
}
