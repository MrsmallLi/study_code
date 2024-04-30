/*************************************************************************
	> File Name: 2.inherit_constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Apr 2024 02:39:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    A() : x(99) {
        cout << "A default constructor" << endl;
    }
    A(int x) : x(x) {
        cout << "A parameter constructor" << endl;
    }
    int get_x() { return this->x; }
private :
    int x;
};


class B : public A{
public :
    //在创建子类对象时，如果明确不调用父类的默认构造函数
    //那就需要在初始化列表中明确调用需要调用的构造函数
    B() : A(98), y(100) {
        cout << "B default constructor" << endl;
    }
    //那么这里就会默认调用父类的默认构造
    B(int y) : y(y) {
        cout << "B parameter constructor" << endl;
    }
    //在调用子类的拷贝构造时，一定要显示的去调用父类的拷贝构造
    //这里调用父类的拷贝构造时，传入的是子类的对象
    //因为子类对象可以当作父类的对象引用
    B(const B &b) : A(b), y(b.y){
        cout << "B copy constructor" << endl;
    }
    B &operator=(const B &obj) {
        //对于子类的拷贝行为时，需要调用父类的拷贝，才能正确的进行拷贝
        this->A::operator=(obj);
        this->y = obj.y;
        return *this;
    }
    void output() {
        cout << get_x() << " " << y << endl;
    }
private :
    int y;
};



int main() {
    B b1;
    B b2(20);
    b1.output();
    b2.output();
    return 0;
}
