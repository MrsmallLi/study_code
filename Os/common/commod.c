/*************************************************************************
	> File Name: commod.c
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jun 2024 01:56:18 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./commod.h"


int make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag &= ~O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}



int make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag |= O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}

