/*************************************************************************
	> File Name: 1.shared_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 12:18:32 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
using namespace std;


class A {
public :
    A() {
        cout << "defaulte constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
    shared_ptr<A> a;
};


int main() {
    shared_ptr<A> p = make_shared<A>();
    shared_ptr<A> q = make_shared<A>();
    p->a = q;
    p->a = p;
    return 0;
}
