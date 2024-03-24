/*************************************************************************
	> File Name: 9.pointer.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Mar 2024 07:26:36 PM CST
 ************************************************************************/

#include<stdio.h>



int main() {
    int *p1;
    double *p2;
    char *p3;
    int a = 123;
    double b = 45.6;
    char c = 'h';
    //p1中存存储着a的地址
    //例如只要有地址，你不会找不到这个位置
    //可以理解位p1指向a
    p1 = &a;
    p2 = &b;
    p3 = &c;
    //查看指针是否指向对应的地址
    printf("p1 = %p, &a = %p\n", p1, &a);
    printf("p2 = %p, &b = %p\n", p2, &b);
    printf("p3 = %p, &c = %p\n", p3, &c);
    //查看指针变量的地址
    printf("&p1 = %p\n", &p1);
    printf("&p2 = %p\n", &p2);
    printf("&p3 = %p\n", &p3);
    //取值运算符
    //是取对应指针里面存储的地址里面所存储的值
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %lf\n", *p2);
    printf("*p3 = %c\n", *p3);
    return 0;
}
