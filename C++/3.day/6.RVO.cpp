/*************************************************************************
	> File Name: 6.struct.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Apr 2024 10:24:22 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    A() {
        cout << this << " default constructor" << endl;
    }
    A(const A &) {
        cout << this << " copy constructor" << endl;
    }
    string s;
};

A func() {
    //这里创建temp调用了默认构造
    A temp;
    cout << "temp = " << &temp << endl;
    temp.s = "hello func";
    //return这里会有一个匿名对象
    //然后temp会通过拷贝构造拷贝给这个匿名对象
    return temp;
}

int main() {
    //然后这里的a通过拷贝构造，拷贝这个匿名对象
    //那么创建a对象最终会调用
    //一次默认构造，两次拷贝构造对吧
    A a = func();
    cout << "a = " << &a << endl;
    return 0;
}
