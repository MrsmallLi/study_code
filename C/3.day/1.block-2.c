/*************************************************************************
	> File Name: 1.block-2.c
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Mar 2024 06:07:46 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    //这里a,b变量存储在外部作用域
    int a = 1, b = 2;
    for (int i = 0; i < 3; i++) {
        //这里的a,b变量存储在内部作用域
        int a = 3, b = 4;
        //如果内外部都有相同名的变量，内部访问都访问自己的变量
        printf("in for: a = %d, b = %d\n", a, b);
    }
    //外部访问外部的变量，是不可访问到内部变量的
    printf("outside : a = %d, b = %d\n", a, b) ;

    return 0;
}
