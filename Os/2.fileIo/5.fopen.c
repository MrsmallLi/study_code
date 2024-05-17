/*************************************************************************
	> File Name: 5.fopen.c
	> Author: 
	> Mail: 
	> Created Time: Fri 17 May 2024 04:04:03 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage : cmd + filename\n");
        return -1;
    }


    FILE *f1 = fopen( argv[1], "r");
    if (!f1) {
        perror("filename is unfind\n");
        exit(1);
    }

    char c;
    while (~(c = fgetc(f1))) {
        printf("%c", c);
    }
    fclose(f1);
    return 0;
}
