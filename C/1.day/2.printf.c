/*************************************************************************
	> File Name: 2.printf.c
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Mar 2024 04:51:52 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n1, n2;
    //n1 接收返回值，printf打印hello world\n, \n计算机识别到是换行
    n1 = printf("hello world\n");
    //打印换行符的ASCII码值
    printf("%d\n", '\n');
    int a = 123;
    n2 = printf("hello world : %d\n", a);
    //打印上面两个用printf打印后的返回值n1, n2的大小
    printf("n1 = %d, n2 = %d\n", n1, n2);



    return 0;
}
