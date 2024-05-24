/*************************************************************************
	> File Name: 6.zomb.c
	> Author: 
	> Mail: 
	> Created Time: Fri 24 May 2024 04:44:26 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
    
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid) {
        while (1) sleep(1);
    } else {
        exit(3);
    }

    return 0;
}
