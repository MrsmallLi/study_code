/*************************************************************************
	> File Name: 1.virtual_funcion.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 29 Apr 2024 06:08:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

namespace test1 {
class Animal{
public :
    virtual void say() = 0;
};

class Cat : public Animal{
public :
    void say() override {
        cout << "Class Cat" << endl;
    }
};

class Dog : public Animal{
public :
    void say() override {
        cout << "Class Dog" << endl;
    }
};

class Bat : public Animal{
public :
    void say() override {
        cout << "Class Bat" << endl;
    }
};

int main() {
    #define MAX_N 5
    srand(time(0));
    Animal *arr[MAX_N + 5];
    for (int i = 0; i < MAX_N; i++) {
        switch (rand() % 3) {
            case 0 : arr[i] = new Dog(); break;
            case 1 : arr[i] = new Cat(); break;
            case 2 : arr[i] = new Bat(); break;
        }
    }
    for (int i = 0; i < MAX_N; i++) arr[i]->say();
    return 0;
}
}

/*
namespace test2{
class A {
public :
    virtual void func() = 0;
};
class B : public A{
public :
};
int main() {
    B b;
    return 0;
}
}
*/

/*
namespace test3{
class A {
public :
    virtual void func() = 0;
};
class B : public A{
public :
    void func() override {};
};
int main() {
    A a;
    return 0;
}
}
*/

int main() {
    //test1中展示了纯虚函数的使用方法
    test1::main();
    //在test2中可以发现B继承A
    //A中有一个纯虚函数func
    //而在B中没有重写func在定义B的对象d会发生报错
    //test2::main();
    //在test3中因为A类是一个抽象类
    //所以这个A类不能定义对象
    //test3::main();
    return 0;
}
