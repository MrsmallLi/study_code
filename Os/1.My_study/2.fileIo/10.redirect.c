/*************************************************************************
	> File Name: 9.fcntlGetOpe.c
	> Author: 
	> Mail: 
	> Created Time: Fri 17 May 2024 05:10:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    write(5, "hello\n", 6);
    return 0;
}
