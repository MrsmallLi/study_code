/*************************************************************************
	> File Name: 5.execOpt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 07:10:54 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>


int main() {
    
    execlp("ls", "ls", "-al", "-l", NULL);
    perror("exec");
    return 0;
}
