/*************************************************************************
	> File Name: 9.args_template.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Jun 2024 03:58:55 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//递归出口,打印最后一个参数
//也就是偏特化版本,只有一个参数时的print
template<typename T>
void print(T a) {
    cout << a << endl;
    return ;
}

//一个模板参数代表当前层数的参数的类型， ARGS代表后续跟着的参数的类型
template<typename T, typename ...ARGS>
void print(T a, ARGS ...args) {
    //打印当前层的的第一个参数
    cout << a << " ";
    //递归到下一层，去打印下一个参数
    print(args...);
    return ;
}


int main() {
    int a = 10;
    print(a, 12.3, "hello", '0', "gg");
    return 0;
}
