/*************************************************************************
	> File Name: 5.commod.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Mar 2024 03:55:59 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    char s[1000] = {0};
    int i = 1;
    while (scanf("%[^\n]", s) != EOF) {
        getchar();
        fprintf(stderr, "%d test\n", i++);
        printf("%s | hello world\n", s);
    }

}
