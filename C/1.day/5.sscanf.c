/*************************************************************************
	> File Name: 5.sscanf.c
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Mar 2024 04:25:15 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b;
    //定义一个字符数组，并赋值;
    char str[100] = "123abc456";
    //变量a, b从str字符数组中读取值
    //sscanf读入str字符数组中的内容就相当于scanf读取在终端上输入的内容
    sscanf(str, "%dabc%d", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
