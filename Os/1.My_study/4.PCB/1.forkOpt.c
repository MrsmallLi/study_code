/*************************************************************************
	> File Name: 1.forkOpt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 04:23:59 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>


int main() {

    int n;
    int state;
    //创建子进程
    //在子进程中child_pid 为0
    //父进程为fork的返回值
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("fork");
        exit(1);
    }

    //当child_pid为04时说明是子进程
    if (child_pid == 0) {
        n = 6;
        while (n > 0) {
            printf("child self = %d, parent = %d\n", getpid(), getppid());
            n--;
        }
    } 
    //不为0说明是父进程
    else {
        n = 3;
        while (n > 0) {
            printf("parent self = %d, parent = %d\n", getpid(), getppid());
            n--;
        }
        int ret = wait(&state);
        if (ret < 0) {
            perror("wait error");
            exit(1);
        }
        //看通过stata判断子进程是否正常退出
        if (WIFEXITED(state)) {
            //正常退出输出子进程PID和退出状态
            printf("child process %d is sucess exit %d\n", child_pid, WEXITSTATUS(state));
        } else {
            //不正常输出子进程PID
            printf("child process %d is not sucess exit\n", child_pid);
        }
    }
    
    return 0;
}
