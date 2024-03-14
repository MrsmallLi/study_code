/*************************************************************************
	> File Name: 8.digit.c
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Mar 2024 06:59:13 PM CST
 ************************************************************************/

#include<stdio.h>

//这里的代码先不用去理解，在学习循环后可以再回头来看
//这里的代码作用就是把数字以二进制形式显示出来
void printf_digit(int x) {
    for (int i = 31; i >= 0; i--) {
        printf("%c", (x & (1 << i)) ? '1' : '0');
    }
    printf("\n");
    return ;
}


int main() {
    int a = 5, b = 3;
    //输出a和b的二进制形式
    printf("a = "); printf_digit(a);
    printf("b = "); printf_digit(b);
    //与运算和或运算
    printf("a & b = "); printf_digit(a & b);
    printf("a | b = "); printf_digit(a | b);
    //异或
    printf("a ^ b"); printf_digit(a ^ b);
    printf("a = %d, b = %d\n", a, b);
    //如何不用第三个变量交换a, b变量中的值
    a ^=  b;//这句代码的意思就是a = a ^ b,同理 a += b,就是 a = a + b;需要两个变量的运算符都可以这样
    b ^=  a;
    a ^=  b;
    //这3句代码，可以在纸上自己画一下这个过程,看是否能交换值
    printf("a = %d, b = %d\n", a, b);
    //按位取反
    printf("~a = "); printf_digit(~a);
    //然后下面是看负数是不是通过正数按位取反在+1得到的
    printf("a = %d\n", a);
    printf("(~a + 1) = %d\n", ~a + 1); 
    //下面是一个练习,如何取得一个数在二进制中最后一位一，也就是从右往左的一个1;
    int x;
    scanf("%d", &x);
    printf("x = "); printf_digit(x);
    printf("(-x & x) = "); printf_digit(-x & x);
    //左移右移
    int c = 123456767, e = -c;
    printf("c = "); printf_digit(c);
    printf("e = "); printf_digit(e);
    //c左移一位
    printf("c << 1 = "); printf_digit(c << 1);
    //c右移一位
    printf("c >> 1 = "); printf_digit(c >> 1);
    //e左移一位
    printf("e << 1 = "); printf_digit(e << 1);
    //e右移一位
    printf("e >> 1 = "); printf_digit(e >> 1);
    //左移等于这个变量乘以2的结果
    printf("c = %d, c << 1 = %d, c / 2 = %d\n", c, c << 1, c * 2);
    //右移等于这个变量除以2的结果
    //但是/ 是向0取证，但是>>是向下取证
    //向下取证就是5 >> 1 = 2，正数和/是没有区别的
    //但是负数-5 >> 1 = -3，而-5 / 2 = -2区别在这儿
    //所以向下取整的意思就是向小的一端去取证
    printf("c = %d, c >> 1 = %d, c / 2 = %d\n", c, c >> 1, c / 2);
    return 0;
}
