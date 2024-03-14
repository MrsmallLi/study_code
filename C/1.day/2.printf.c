/*************************************************************************
	> File Name: 2.printf.c
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Mar 2024 04:51:52 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    //用int类型 定义 n1, n2两个变量
    int n1, n2;
    //返回值不懂没关系，下面这句代码的意思就是n1 接收了printf这个函数的返回值
    //n1 接收返回值，printf打印hello world\n, '\n'是一个字符,在ASCII码表上有，而计算机识别到打印出来就是换行
    n1 = printf("hello world\n");
    //打印换行符的ASCII码值
    printf("%d\n", '\n');
    int a = 123;
    //%d是占位符，就是为变量a占用一个位置，来打印变量a里存储的值
    //不同类型的变量，占位符是不同的
    n2 = printf("hello world : %d\n", a);
    //打印上面两个用printf打印后的返回值n1, n2的大小
    printf("n1 = %d, n2 = %d\n", n1, n2);



    return 0;
}
