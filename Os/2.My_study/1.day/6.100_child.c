/*************************************************************************
	> File Name: 6.100_child.c
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Jun 2024 07:21:52 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int *a;
int *cnt;

int main() {
    pid_t fatherpid = getpid();
    a = (int *)malloc(sizeof(int));
    cnt = (int *)malloc(sizeof(int));
    *cnt = 100;
    *a = 1;
    while ((*cnt)--) {
        pid_t pid = fork();
        pid_t pid_now = getpid();
        pid_now != fatherpid && printf("I am %d childs\n", *a);
        (*a)++;
        if (pid_now != fatherpid) break;
    }
    if (getpid() == fatherpid) {
        free(a);
        free(cnt);
    }
    return 0;
}
