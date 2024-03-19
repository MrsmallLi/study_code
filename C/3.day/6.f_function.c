/*************************************************************************
	> File Name: 6.f_function.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Mar 2024 12:58:55 PM CST
 ************************************************************************/

#include<stdio.h>

int func(int n) {
    if (n == 1) return 1;
    return n * func(n - 1);
}


int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("!n = %d\n", func(n));
    }
    return 0;
}
