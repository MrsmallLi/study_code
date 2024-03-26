/*************************************************************************
	> File Name: 9.string_cat.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Mar 2024 02:59:17 PM CST
 ************************************************************************/

#include<stdio.h>

#define STR(n) #n
//这里的宏表示 执行func函数，并且打印func函数名以表func函数执行结束
#define RUN(func) {\
    func;\
    printf("%s done\n", #func);\
}

//这个宏定义的作用是将a和b进行连接到一起
#define CAT(a, b) a##b
void test1() {
    printf("this is test1()\n");
    return ;
}

void test2(int a, int b) {
    printf("this is test2(): a = %d, b = %d\n", a, b);
    return ;
}

int main() {
    printf("%s\n", STR(hello));
    RUN(test1());
    RUN(test2(1, 2));
    int n10 = 123, n11 = 456;
    CAT(n, 10) = 789;
    printf("n10 = %d, n11 = %d\n", n10, n11);
    return 0;
}
