/*************************************************************************
	> File Name: 7.wait.c
	> Author: 
	> Mail: 
	> Created Time: Fri 24 May 2024 05:03:29 PM CST
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
    
    if (pid == 0) {
        int n = 5;
        while (n > 0) {
            printf("this is child process\n");
            sleep(1);
            n--;
        }
    } else {
        int stat_val;
        waitpid(pid, &stat_val, 0);
        if (WIFEXITED(stat_val)) {
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        } else if (WIFSIGNALED(stat_val)) {
            printf("Child terminated abnormally, signal %d\n", WTERMSIG(stat_val));
        }
    }
    return 0;
}
