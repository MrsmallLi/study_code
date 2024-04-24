/*************************************************************************
	> File Name: 8.operator=.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Apr 2024 04:56:10 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    A() {
        cout << "default constructor " << this << endl;
    }
    A(const A &a) {
        cout << "copy constructor " << this << endl;
    }
    A(const A &&a) {
        cout << "move constructor " << this << endl;
    }
    //对于=重载
    A &operator=(const A &a) {
        //new关键字的原地构造
        //在this指针这块位置调用拷贝构造
        //this指针指向的就是下面的对象c
        new(this) A(a);
        cout << "operator= " << this << endl;
        return *this;
    }
    A &operator=(A &&a) {
        new(this) A(move(a));
        cout << "operator= " << this << endl;
        return *this;
    }
};


int main() {
    A a, c, d;
    A b = a;
    c = a;
    d = move(a);
    cout << "a = " << &a << endl;
    cout << "b = " << &b << endl;
    cout << "c = " << &c << endl;
    cout << "d = " << &d << endl;
    return 0;
}
