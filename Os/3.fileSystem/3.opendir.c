/*************************************************************************
	> File Name: 3.opendir.c
	> Author: 
	> Mail: 
	> Created Time: Mon 20 May 2024 04:31:08 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void printDir(char *dirname) {
    char pathname[1024];
    DIR *dir = NULL;
    struct dirent *dp;
    struct stat st;
    dir = opendir(dirname);
    if (!dir) {
        perror("opendir is error");
        exit(1);
    } 

    while ((dp = readdir(dir))) {

        if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..")) continue;

        sprintf(pathname, "%s/%s", dirname, dp->d_name);
        if (stat(pathname, &st) < 0) {
            perror("stat error\n");
            exit(1);
        }
        if(S_ISDIR(st.st_mode)) {
            printDir(pathname);
        }
        printf("%s\t", dp->d_name);
    }
    putchar(10);
    closedir(dir);
}




int main(int argc, char *argv[]) {

    if (argc < 2)  {
        printf("usage : cmd + dirname\n");
        exit(1);
    }
    printDir(argv[1]);
    return 0;
}
