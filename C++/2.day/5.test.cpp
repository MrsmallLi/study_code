/*************************************************************************
	> File Name: 5.test.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Apr 2024 07:20:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class C {
public:
    C(int n) {
        this->num = n;
        cout << "C coversion constructor" << endl;
    }
    void output() {
        cout << num;
    }
private :
    int num;
};

class A {
public :
    //:后面是构造函数的初始化列表
    A(int a) : a(a), b(10), c(6) {
        cout << "A constructor" << endl;
    }
    void output() {
        cout << " " <<a << " " << b << " ";
        c.output();
        cout << endl;
        return ;
    }
private :
    int a, b;
    C c;
};


int main() {
    A a(2);
    a.output();
    return 0;
}
