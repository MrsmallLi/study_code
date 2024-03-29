/*************************************************************************
	> File Name: 8.getchar.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Mar 2024 07:06:44 PM CST
 ************************************************************************/

#include<stdio.h>


int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    //利用getchar吞掉换行符
    getchar();
    char c = 'x';
    scanf("%c", &c);
    printf("a = %d, b = %d, c = %c\n", a, b, c);
    return 0;
}
