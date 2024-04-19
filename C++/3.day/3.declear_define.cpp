/*************************************************************************
> File Name: 1.static_method.cpp
> Author: 
> Mail: 
> Created Time: Wed 17 Apr 2024 10:48:46 AM CST
************************************************************************/

#include<iostream>
using namespace std;

//在类中只放方法的声明
class Point {
    public :
    Point();
    Point(int x, int y);
    void set_x (int x);
    void set_y (int y);
    int get_x() const;
    int get_y() const;
    static int x_cnt();
    private :
    static int get_x_cnt;
    int x, y;
};

//对于类中的方法进行实现
//那么就可以将这两部分拆开
//定义放在源文件中，声明放在头文件中
Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y) {}
void Point::set_x(int x) {
    this->x = x; 
}

void Point::set_y(int y) {
    this->y = y; 
}

int Point::get_x() const{
    Point::get_x_cnt += 1;
    return x; 
}

int Point::get_y() const{
    return y;
}

int Point::x_cnt() {
    return Point::get_x_cnt; 
}

int Point::get_x_cnt = 0;

int main() {
    Point p1(3, 4), p2(5, 6);
    cout << p1.get_x() << ", " << p1.get_y() << endl;
    cout << p2.get_x() << ", " << p2.get_y() << endl;
    p1.get_x();
    p1.get_x();
    p1.get_x();
    cout << "x_cnt : " << Point::x_cnt() << endl;
    return 0;
}
