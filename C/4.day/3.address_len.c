/*************************************************************************
	> File Name: 3.address_len.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Mar 2024 03:54:19 PM CST
 ************************************************************************/

#include<stdio.h>


int main() {
    int a;
    double b;
    char c;
    //获取每个类型的地址长度
    //sizeof获取参数的对应字节长度
    printf("sizeof(int &) = %lu\n", sizeof(&a));
    printf("sizeof(double &) = %lu\n", sizeof(&b));
    printf("sizeof(char &) = %lu\n", sizeof(&c));
    return 0;
}
