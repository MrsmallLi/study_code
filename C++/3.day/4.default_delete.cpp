/*************************************************************************
	> File Name: 4.default_delete.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Apr 2024 03:06:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    //A() = delete;
    A() {
        cout << "default constructor" << endl;
    }
    A(int n) : x(n) {
        cout << "conversion constructor" << endl;
    }
    A(const A &) {
        cout << "copy constructor" << endl;
    }
private :
    int x;
};

class B {
public :
    B() = default;
    B(const B&) = default;
private :
    A a1, a2, a3;
};

class C {
public :
    C() = default;
    //C(const C&) {}//这种情况叫撒比构造
    C(const C&) = default;
private :
    A a1, a2, a3;
};

class Point {
public :
    Point() = default;//请求编译器生成默认构造函数
    Point(int x, int y) : x(x), y(y) , p(new int(5)), a(1){}
    //Point(const Point &) = delete;//删除编译器的拷贝构造函数
    //Point(const Point &) = default;//拷贝函数生成默认行为,在使用这个拷贝构造函数时就会造成双重释放的报错
    //这就是深拷贝
    Point(const Point &a) : x(a.x + 1), y(a.y + 2), a(a.a){
        //如果这里成员属性a直接用这样去赋值拷贝
        //那么成员属性a就会使用A类的默认构造函数进行构造
        //而A类的默认构造函数已经被删除了，那么就会报错
        //this->a = a.a;
        this->p = new int;
        *(this->p) = *(a.p);
    }
    ~Point() {
        delete p;
    }
private :
    A a;
    int *p;
    int x, y;
};


int main() {
    Point p1(1, 2), p2 = p1;
    return 0;
}
