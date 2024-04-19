/*************************************************************************
> File Name: 1.static_method.cpp
> Author: 
> Mail: 
> Created Time: Wed 17 Apr 2024 10:48:46 AM CST
************************************************************************/

#include<iostream>
using namespace std;


class Point {
    public :

    Point() : x(0), y(0) {} //默认构造
    //区分x和y
    //在x(x),括号外是成员属性x,括号内是形参x
    Point(int x, int y) : x(x), y(y) {} //有参构造
    void set_x (int x) { this->x = x; }
    void set_y (int y) { this->y = y; }
    int get_x() { 
        //访问类中的类属性
        Point::get_x_cnt += 1;
        return this->x; 
    }
    int get_y() { return this->y; }
    //这里是直接定义了类方法
    static int x_cnt() {
        return Point::get_x_cnt;
    }
    private :
    //这里只是声明了这个变量
    //get_x_cnt,记录变量x在被get时,在整个程序执行时被调用了多少次
    static int get_x_cnt;
    int x, y;
};

//这里就是定义了get_x_cnt, 并且给他的值进行了初始化
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
