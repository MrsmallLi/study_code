/*************************************************************************
	> File Name: 7.exec.c
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Jun 2024 03:08:46 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


int main() {
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    if (pid = 0) {
        execlp("ping", "ping", "haizeix.com", NULL);
        printf("Hello, I'm child, I returned from execlp\n");
        exit(0);
    }
    return 0;
}
