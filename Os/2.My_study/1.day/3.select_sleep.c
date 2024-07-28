/*************************************************************************
	> File Name: 3.select_sleep.c
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Jun 2024 05:39:22 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int my_sleep(int sec) {
    struct timeval tv;
    tv.tv_sec = sec;
    tv.tv_usec = 0;
    int ret = select(0, NULL, NULL, NULL, &tv);
    if (ret < 0) {
        return -1;
    }
    return 0;
}


int main() {
    my_sleep(3);
    printf("End\n");
    return 0;
}
