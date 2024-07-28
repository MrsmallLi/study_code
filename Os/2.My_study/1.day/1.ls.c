/*************************************************************************
	> File Name: 1.ls.c
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Jun 2024 11:22:41 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int flag_a = 0;
int flag_l = 0;

int main(int argc, char **argv) {
    int opt;
    while ((opt = getopt(argc, argv, "al")) != -1) {
        switch (opt) {
            case 'a': {
                flag_a = 1;
            } break;
            case 'l': {
                flag_l = 1;
            } break;   
            default: {
                fprintf(stderr, "Usage : %s[-al][filename]\n", argv[0]);
                exit(1);
            } 
        }
    }
    printf("flag_a = %d, flag_l = %d\n", flag_a, flag_l);
    printf("optind = %d\n", optind);
    argc -= (optind - 1);
    argv += (optind - 1); 

    return 0;
}
