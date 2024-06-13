/*************************************************************************
	> File Name: callback.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 07:26:32 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    
    if (argc < 3) {
        printf("usage : cmd + inputfile + outputfile\n");
        exit(1);
    }
    
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open error");
        exit(1);
    }

    dup2(fd, STDIN_FILENO);
    close(fd);
    fd = open(argv[2], O_WRONLY);
    if (fd < 0) {
        perror("open error");
        exit(1);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    execl("./upper", "./upper", NULL);
    perror("exec");
    exit(1);
}
