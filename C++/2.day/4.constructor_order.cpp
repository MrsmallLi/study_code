/*************************************************************************
	> File Name: 4.constructor_order.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Apr 2024 06:59:05 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


class A {
public :
    A() {};
    A(string n)  {
        name = n;
        cout << name << " class A construtor" << endl;
    }
    ~A() {
        cout << name << " class A destructor" << endl;
    }
int *p;
private :
    string name;
};

class B {
public :
    //:a(a)
    //:后面是构造函数时，最该对象中的成员属性进行初始化操作
    B(string n, A &a) : a(a){
        name = n;
        cout << name << " class B construtor" << endl;
        //new关键字可以理解为，C语言中malloc去堆区中开辟一段空间
        a.p = new int[10];
        return ;
    }
    A &a;//创建一个引用属性，这里&a可以暂时理解为取a的地址
    ~B() {
        //delete就相当于C语言中的free对开辟空间的释放
        delete a.p;
        cout << name << " class B destructor" << endl;
    }
private :
    string name;
};


int main() {
    A a("a");
    B b("b", a);
    return 0;
}
