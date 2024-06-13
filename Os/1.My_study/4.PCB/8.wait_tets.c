/*************************************************************************
	> File Name: 8.wait_tets.c
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 02:39:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

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
        exit(3);
    } else {
        int stat_val;
        waitpid(pid, &stat_val, 0);
        if (WIFEXITED(stat_val)) {
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        } else if (WIFSIGNALED(stat_val)) {
            printf("Child terminated abnormally, signal%d\n", WTERMSIG(stat_val));
        }
    }
    return 0;
}
