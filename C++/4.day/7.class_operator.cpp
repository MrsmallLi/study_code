/*************************************************************************
	> File Name: 7.class_operator.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Apr 2024 04:31:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Point {
public :
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point &a) : x(a.x), y(a. y) {}
    //+重载, p1 + p2 就是 p1.x + p2.x, p1.y + p2.y
    //因为返回的是一个新的值，所以是右值，返回值类型就不是引用,也就是不是左值
    Point operator+(const Point &p) {//他这里是成员方法，比如它可以访问this指针
        Point ret(x + p.x, y + p.y);
        return ret;
    }
    //由于是前++，就不需要参数
    //前++返回的是左值，所以返回值类型也是左值
    //返回的对象也是本身
    Point &operator++() {
        cout << "++class" << endl;
        this->x += 1, this->y += 1;
        return *this;
    }
    //后++是一个右值，在演示左值和右值代码中有示例
    //那么返回的是一个新的值,所以返回值类型也是右值,而不是左值引用
    //参数列表中有参数，就是后++
    Point operator++(int) {
        cout << "class++" << endl;
        Point ret(*this);
        //代码设计逻辑和技巧
        ++(*this);
        return ret;
    }
    friend ostream &operator<<(ostream &out, const Point &p);
private :
    int x, y;
};

ostream &operator<<(ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}


int main() {
    Point a(1, 2), b(3, 4);
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
    cout << a + b << endl;
    //这样去调用运算符重载的函数和上行代码执行效果一样
    cout << a.operator+(b) << endl;
    cout << "++a : " << ++a << endl;
    cout << "b++ : "<< b++ << endl;
    cout << "b : "<< b << endl;
    return 0;
}
