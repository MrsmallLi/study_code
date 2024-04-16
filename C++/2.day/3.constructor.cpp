/*************************************************************************
	> File Name: 3.constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Apr 2024 06:03:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    A() {//默认构造函数
        cout << "default constructor" << endl;
    }
    //如果这里没有const关键字,传入的对象是const声明的那么就会报错
    //如果没有&(引用),那么将会造成无限套娃的拷贝构造
    //假如这里没有&，那么这里的形参就相当于实参给他赋值
    //而赋值就是 A a = b, b是实参传入的值
    //那这里就会又调用构造函数,形成无限套娃
    A(const A &a) {
        this->x = a.x;
        this->y = a.y;
        cout << "copy constructor" << endl;
    }
    A(int x, int y) {//有参构造函数
        cout << "have parameter constructor" << endl;
        this->x = x;//this表示当前对象的地址
        this->y = y;
    }
    void operator=(const A &a) {//这个函数是=运算符重载，是类中默认有的
        cout << "this is assigment"  << endl;
        return ;
    }
    A(int x) {//转换构造函数
        cout << "conversion constructor" << endl;
        this->x = x;
        this->y = 0;
    }
    void output() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    ~A() {//析构函数
        cout << "destructor" << endl;
    }
private :
    int x, y;
};


void func(A a) {
    cout << "func : ";
    a.output();
    return ;
}


int main() {
    A a;//调用默认构造函数
    cout << "1-------------------------" << endl;
    A b(1, 2);//调用有参构造
    cout << "2-------------------------" << endl;
    //这里就调用了拷贝构造函数
    A e = b;
    cout << "3-------------------------" << endl;
    //这里只是运用了普通赋值运算符
    //通过执行会发现没有执行任何构造函数
    a = b;
    cout << "4-------------------------" << endl;
    //调用转换构造，将int类型转换为A类型
    //这里也可以是另一个类型的对象，那也是转换构造
    //不过还需要从新定义一个需要转换构造的函数,里面的参数就是对应的类型
    A c(3);
    cout << "5-------------------------" << endl;
    //这里调用的是拷贝构造函数，将对象b进行拷贝给函数形参a
    func(b);
    func(c);
    cout << "6-------------------------" << endl;
    //对于这中函数调用情况
    //这里就会用到转换构造
    //他会隐式的将int类型5通过转换构造转会为A类型
    func(5);
    cout << "7-------------------------" << endl;
    //这里相当于A d(4);
    //这里可以这样理解
    //等号类型相同编程才能通过
    //那么4，int类型就会通过转换构造变成A类型
    //如果没有转换构造那么就编译无法通过
    A d = 4;
    a = 6;
    cout << "8-------------------------" << endl;
    return 0;
}

