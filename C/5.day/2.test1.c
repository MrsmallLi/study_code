/*************************************************************************
	> File Name: 2.test1.c
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Mar 2024 07:27:50 PM CST
 ************************************************************************/

#include<stdio.h>

int add(int, int);

int main() {
    int a = 123, b = 456;
    printf("%d", a + b);
    printf("add(%d, %d) = %d\n", a, b, add(a, b));
    return 0;
}
