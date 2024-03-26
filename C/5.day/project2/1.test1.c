/*************************************************************************
	> File Name: 3.test2.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Mar 2024 10:05:19 AM CST
 ************************************************************************/

#include<stdio.h>

int add(int, int);

int main() {
    int a = 123, b = 456;
    printf("a + b = %d\n", a + b);
    printf("add(%d, %d) = %d\n", a, b, add(a, b));
    return 0;
}
