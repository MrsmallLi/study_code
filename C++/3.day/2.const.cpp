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
    Point() : x(0), y(0) , get_x_cnt(0){} //默认构造
    Point(int x, int y) : x(x), y(y), get_x_cnt(0) {} //有参构造
    void set_x (int x) { this->x = x; }
    void set_y (int y) { this->y = y; }
    int get_x() const { //修改处
        get_x_cnt += 1;
        return this->x; 
    }
    int get_y() const { return this->y; }//修改处
    int x_cnt() const {//修改处
        return get_x_cnt;
    }
    private :
    //现在get_x_cnt，表示当前对象对get_x函数的调用次数
    //mutable关键字表示不收const关键之的限制
    //所以就算有const关键字，那么mutable声明的变量也可以进行修改
    mutable int get_x_cnt;
    int x, y;
};




int main() {
    const Point p(10, 15), p2(1, 2);
    cout << p.get_x() << ", " << p.get_y() << endl;
    p2.get_x();
    p2.get_x();
    cout << "p1 : get_x_cnt = " << p.x_cnt() << endl;
    cout << "p2 : get_x_cnt = " << p2.x_cnt() << endl;
    return 0;
}
