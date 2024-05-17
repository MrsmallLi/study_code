/*************************************************************************
	> File Name: 11.ioctl.c
	> Author: 
	> Mail: 
	> Created Time: Fri 17 May 2024 10:41:36 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    struct winsize size; 
    
    if (!isatty(1)) {
        printf("1 is not tty\n");
        exit(1);
    }
    
    if (ioctl(1, TIOCGWINSZ, &size) == -1) {
        perror("ioctl is error");
        exit(1);
    }

    printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
    return 0;
}
