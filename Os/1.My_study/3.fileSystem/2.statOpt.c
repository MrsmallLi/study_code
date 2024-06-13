/*************************************************************************
	> File Name: 1.statOpt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 20 May 2024 03:50:50 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    struct stat st;
    if (argc < 2) {
        printf("usage : cmd + filename/dirname\n");
    }

    stat(argv[1], &st);

    switch (st.st_mode & S_IFMT) {
        case S_IFREG : printf("regular file\n"); break;
        case S_IFDIR : printf("directory\n"); break;
        case S_IFCHR : printf("charactor file\n"); break;
        default : printf("other file\n"); break;
    }
    return 0;
}
