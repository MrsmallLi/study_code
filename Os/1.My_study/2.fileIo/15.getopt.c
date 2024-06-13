/*************************************************************************
	> File Name: 15.getopt.c
	> Author: 
	> Mail: 
	> Created Time: Sun 26 May 2024 05:44:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
    int opt;
    char name[25] = {0};
    char gender[25] = "男";
    int age = 18;
    while ((opt = getopt(argc, argv, "n:a:g:")) != -1) {
        switch(opt) {
            case 'n' : {
                strncpy(name, optarg, sizeof(optarg));
            } break;
            case 'a' : {
                age = atoi(optarg);
            } break;
            case 'g' : {
                strncpy(gender, optarg, sizeof(optarg));
            } break;
            default : {
                fprintf(stderr, "Usage : %s -n name -a age -g gender\n", argv[0]);
                return 1;
            }
        }
    }
    printf("optind : %d\n", optind);
    printf("optarg : %s\n", optarg);
    printf("Name : %s\n", name);
    printf("Age : %d\n", age);
    printf("Gender : %s\n", gender);
    return 0;
}
