/*************************************************************************
	> File Name: 4.polymorphism.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 29 Apr 2024 01:20:58 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal {
public :
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
};

class Cat : public Animal{
public :
    void run() {
        cout << "I can run with four legs" << endl;
    }
};

class Bat : public Animal{
public :
    void run() {
        cout << "I can fly" << endl;
    }
};

#define P(func) {\
    printf("%s : ", #func);\
    func;\
}

int main() {
    Cat c;
    //子类的对象可以隐式的转换为父类的类型
    Animal &a = c;
    Animal *p = &c;
    P(c.run());
    P(a.run());
    P(p->run());
    return 0;
}
