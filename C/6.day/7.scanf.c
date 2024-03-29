/*************************************************************************
	> File Name: 7.scanf.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Mar 2024 06:57:04 PM CST
 ************************************************************************/

#include<stdio.h>


int main() {
    char c1, c2;
    int a, b;
    scanf("%d", &a);
    scanf("%c%c", &c1, &c2);
    scanf("%d", &b);
    printf("a = %d, b = %d\n", a, b);
    printf("c1 = %d, c2 = %d\n", c1, c2);
    return 0;
}
