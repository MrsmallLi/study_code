/*************************************************************************
	> File Name: 3.virtual_fucntion_table.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 03 May 2024 01:46:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base {
public :
    virtual void say(int x) {
        cout << this << endl;
        cout << "Class Base : " << x << endl;
    }
};

class A : public Base {
public :
    void say(int x) override {
        cout << this << endl;
        cout << "Class A : " << x << endl;
    }
    int x;
};

class B : public Base {
public :   
    void say(int x) override {
        cout << this << endl;
        cout << "Class B : " << x << endl;
    }
    int x;
};

typedef void (*func_t)(void *, int);

int main() {
    A a1, a2;
    B b;
    Base *p1 = &a1, *p2 = &a2, *p3 = &b;
    cout << "sizeof(A) :" << sizeof(A) << endl;
    cout << "sizeof(B) :" << sizeof(B) << endl;
    //((void **)(&a1))[0]获取a1对象的虚函数表的地址
    cout << "Class A(a1) virtual function address : " << ((void **)(&a1))[0] << endl;
    cout << "Class A(a2) virtual function address : " << ((void **)(&a2))[0] << endl;
    cout << "Class B virtual function address : " << ((void **)(&b))[0] << endl;
    //通过原生指针调用say()方法
    p1->say(1);
    cout << "================" << endl;
    p2->say(2);
    cout << "================" << endl;
    p3->say(3);
    cout << "================" << endl;
    ((func_t **)(&a2))[0][0](&a2, 97);
    return 0;
}
