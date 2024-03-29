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
    fflush(stdin);
    //利用fflush进行对stdin缓冲区进行冲刷
    char c = 'x';
    scanf("%c", &c);
    printf("a = %d, b = %d, c = %c\n", a, b, c);
    return 0;
}
