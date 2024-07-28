/*************************************************************************
	> File Name: 15.shared_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jun 2024 02:08:17 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
using namespace std;


class B; // 前向声明

class A {
public:
    A() {
        cout << "A contructor" << endl;
    }
    std::weak_ptr<B> b_ptr;
    ~A() { std::cout << "A destroyed" << std::endl; }
};

class B {
public:
    B() {
        cout << "B contructor" << endl;
    }
    std::weak_ptr<A> a_ptr;
    ~B() { std::cout << "B destroyed" << std::endl; }
};

int main() {
    shared_ptr<A> a = std::make_shared<A>();
    shared_ptr<B> b = std::make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;
    return 0;
}
