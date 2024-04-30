/*************************************************************************
	> File Name: 1.virtual_function.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 29 Apr 2024 06:07:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


class Base {
public :
    Base(){
        cout << "Base constructor" << endl;
    }
    virtual ~Base(){
        cout << "Base destructor" << endl;
    }
};

class A : public Base {
public :
    A() : data(new int[0]) {
        cout << "A constructor" << endl;
    }
    ~A() override {
        delete[] data;
        cout << "A destructor" << endl;
    }
    int *data;
};

int main() {
    //这里Base类的指向A类型的对象
    //如果析构函数不是虚函数
    //在析构p时，那么会调用Base类的析构函数
    //而不是调用对象对应的A类中的析构函数
    //那么就会造成内存泄漏
    //比如这里data通过A类的构造函数中new关键字获取了内存
    //而没有通过A类中的析构函数将对应的内存给释放掉
    Base *p = new A();
    delete p;
    return 0;
}
