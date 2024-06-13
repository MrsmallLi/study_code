/*************************************************************************
	> File Name: 9.pipe.c
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 03:12:17 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    pid_t pid;
    int fd[2], n;
    char buff[20] = {0};

    if (pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
        close(fd[0]);
        write(fd[1], "hello pipe\n", 11);
        wait(NULL);
    } else {
        close(fd[1]);
        sleep(1);
        n = read(fd[0], buff, 20);
        write(1, buff, n);
    }
    return 0;
}
