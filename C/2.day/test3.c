/*************************************************************************
	> File Name: test3.c
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Mar 2024 05:07:28 PM CST
 ************************************************************************/

#include<stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("HEHE");
    } else if (n > 0 && n < 60) {
        printf("FAIL");
    } else if (n >= 60 && n < 75) {
        printf("MEDIUM");
    } else if (n >= 75 && n <= 100) {
        printf("GOOD");
    }
    printf("\n");
    return 0;
}
