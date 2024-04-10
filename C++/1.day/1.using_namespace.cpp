/*************************************************************************
	> File Name: 1.using_namespace.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Apr 2024 09:16:04 AM CST
 ************************************************************************/

#include<iostream>

namespace A {
    void func_1() {
        printf("hello world A\n");
        return ;
    }
}

namespace B {
    void func_1() {
        printf("hello world B\n");
        return ;
    }
}


int main() {
    //在A B 空间中都有一个函数func_1
    //为了避免发生命名冲突，那么就需要隔离命名空间来定义
    //在分别调用函数时，需要在函数名前加上命名空间
    A::func_1();
    B::func_1();
    return 0;
}
