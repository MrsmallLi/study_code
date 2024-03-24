/*************************************************************************
	> File Name: 2.hex.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Mar 2024 03:33:30 PM CST
 ************************************************************************/

#include <stdio.h>
#include <limits.h>
int main() {
    //如果要用十六进制对变量赋值
    //需要在赋值前加上0x
    int a = 0x6f;
    //打印a变量对应10进制的值
    printf("a(10) = %d\n", a);
    //打印a变量对应16进制的值
    //%x是十六进制对应的格式占位符
    printf("a(16) = %x\n", a);
    //打印a变量对应16进制的值
    //%X是十六进制对应的格式占位符
    //但是对应小写和大写的作用是
    //打印时十六进制不是会有字母吗
    //然后这里的大小写对应就是把那些字母规定打印时是小写还是大写
    printf("a(16) = %X\n", a);
    //用16进制表示整形最大值和最小值
    printf("MAX_INT = %d\n", INT_MAX);
    printf("MIN_INT = %d\n", INT_MIN);
    int max_int = 0x7fffffff;
    int min_int = 0x80000000;
    printf("max_int = %d\n", max_int);
    printf("min_int = %d\n", min_int);
    return 0;
}
