/*************************************************************************
	> File Name: 5.reference_object.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Apr 2024 05:15:18 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    A() = default;
    A(const A&) = default;
private :

};

class B {
public :
    B(A &a) : a(a) {}
private :
    A &a;
};

class C {
public :
    C()  = default;
    C(const C &) = default;
    static void destroy(C *c) {
        delete c; 
        return ;
    }
private :
    ~C() {}
};

int main() {
    A a;
    B b(a);
    C *c = new C();
    C::destroy(c);
    return 0;
}
