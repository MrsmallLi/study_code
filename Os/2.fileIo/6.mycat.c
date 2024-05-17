/*************************************************************************
	> File Name: 5.fopen.c
	> Author: 
	> Mail: 
	> Created Time: Fri 17 May 2024 04:04:03 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage : cmd + filename + cpfilename\n");
        return -1;
    }


    FILE *f1 = fopen( argv[1], "r");
    FILE *f2 = fopen( argv[2], "w+");
    if (!f1) {
        perror("filename is unfind\n");
        exit(1);
    }
    if (!f2) {
        fclose(f1);
        perror("open cpfilename error\n");
        exit(1);
    }
    char c;
    while (~(c = fgetc(f1))) {
        fputc(c, f2);
    }
    

    fclose(f1);
    fclose(f2);
    return 0;
}
