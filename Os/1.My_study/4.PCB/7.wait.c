/*************************************************************************
	> File Name: 7.wait.c
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 01:48:22 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid) {
        while (1) {
            sleep(1);
        }
    } else {
        exit(3);
    }
    return 0;
}
