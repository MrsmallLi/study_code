/*************************************************************************
	> File Name: 3.mult_inherit.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Apr 2024 03:09:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    int x, y;
};

class B : virtual public A {
public :
    void set_x() { this->x = 99; }
};

class C : virtual public A {
public :
    void set_y() { this->y = 99; }
    void output() {
        cout << x << " " << y << endl;
    }
};

class D : public B, public C {
public :
};

int main() {
    D d;
    d.set_x();
    d.set_y();
    d.output();
    return 0;
}
