/*************************************************************************
	> File Name: 7.operator.c
	> Author: 
	> Mail: 
	> Created Time: Sun 10 Mar 2024 05:47:14 PM CST
 ************************************************************************/

#include <stdio.h>



int main() {
    //定义三个变量
    // a = 5就是赋值运算符的用法
    int a = 5, b = 2, c = 10;
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    // a = b也是，可以用一个变量去赋值另一个变量
    int s = b;
    printf("s = %d\n", s);
    // + - * 运算符
    printf("a + b = %d\n", a + b);
    printf("c - b = %d\n", c - b);
    printf("a * b = %d\n", a * b);
    // / 运算符
    // 这里c / b是可以整除那么得出的值为5
    printf("c / b = %d\n", c / b);
    // 这里a / b是无法整除的,那么这里有个规则就是向0取整,就是2
    printf("a / b = %d\n", a / b);
    // 这里d / b 也是无法整除的,那么他向0取整就是-2
    int d = -5;
    printf("d / b = %d\n", d / b);
    //运算符还可以吧运算后的结果去赋值变量也是可以的
    int n = a + b;
    printf("n = a + b = %d\n", n);
    // % 取余运算
    // 这里如果需要用printf打印%这个符号就需要用%%
    printf("a %% b = %d\n", a % b);
    return 0;
}
