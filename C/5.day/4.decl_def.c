/*************************************************************************
	> File Name: 4.decl_def.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Mar 2024 10:27:25 AM CST
 ************************************************************************/

#include<stdio.h>
//声明add函数
int add(int, int);

//声明c, d变量
extern int c, d;

int main() {
    //定义a，b变量
    int a = 1, b = 2;
    printf("a + b + c + d = %d\n", a + b + c + d);
    return 0;
}

//定义add函数
int add(int a,int b) {
    return a + b;
}
