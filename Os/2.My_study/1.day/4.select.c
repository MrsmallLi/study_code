/*************************************************************************
	> File Name: 4.select.c
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jun 2024 05:44:00 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include "../common/commod.h"


int main() {
    int age = 18; 
    fd_set rfds;

    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    int ret;
    if ((ret = select(1, &rfds, NULL, NULL, &tv)) <= 0) {
        fprintf(stderr, "Nothing read\n");
        make_nonblock(0);
    }
    scanf("%d", &age);
    printf("lsk is %d years olds\n", age);
    return 0;
}

