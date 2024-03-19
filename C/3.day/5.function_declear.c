/*************************************************************************
	> File Name: 5.function_declear.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Mar 2024 12:42:45 PM CST
 ************************************************************************/

#include<stdio.h>

//如果没有这一行，那么在编译的过程中会报错
//因为程序的执行流程是从上到下的
int func_b(int x);

int func_a(int x) {
    //如果没有上面的声明,那么编译器就会不知道有func_b这个函数的存在
    //就会发生编译错误
    //所以这就是声明的作用
    if (x == 1) return func_b(x);
    printf("func_a : x * 2 = %d\n", x * 2);
    return 0;
}

int func_b(int x) {
    if (x == 2) return func_a(x);
    printf("func_b : x * 3 = %d\n", x * 3);
    return 0;
}

int main() {
    //该程序实现的是
    //func_a函数传入的x为1就去调用func_b
    //如果不为1就打印x * 2的值
    //func_b函数传入的x位2就去调用func_a
    //如果不为2就打印x * 3的值
    func_a(2);
    func_a(1);
    return 0;
}
