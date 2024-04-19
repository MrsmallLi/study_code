/*************************************************************************
	> File Name: 1.operator_overload.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Apr 2024 03:46:32 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_N 20

class Point {
public :
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    ~Point() {}
    static void init_x_y_axis() {
        for (int i = 0; i < MAX_N; i++) {
            Point::x_y_axis[i] = new int[MAX_N + 5];
        }
        return ;
    }
    static void set_x_y_axis(int x, int y) {
        if (x_y_axis[x + MAX_N / 2][y + MAX_N / 2]) return ;
        x_y_axis[x + MAX_N / 2][y + MAX_N / 2] = 1;
        return ;
    }
    void output() {
        cout << sizeof(Point::x_y_axis[0]) << endl;
        cout << sizeof(Point::x_y_axis) << endl;
    }

    friend Point &operator^(Point &, Point &);
    friend Point &operator^(Point &, int);
    friend ostream &operator<<(ostream &, const Point &);
private :
    int x, y;
    //创建一个类属性
    //用来当作坐标轴
    static int **x_y_axis;
};

int **Point::x_y_axis = new int*[MAX_N + 5];


Point &operator^(Point &p1, Point &p2) {
    //将每个对象的x,y输出到坐标轴中
    Point::set_x_y_axis(p1.x, p1.y);
    Point::set_x_y_axis(p2.x, p2.y);
    return p1;
}

Point &operator^(Point &p1, int num) {
    //我们要求的是^1才打印
    if (num != 1) return p1;
    for (int y = MAX_N / 2; y > -MAX_N / 2; y--) {
        for (int x = -MAX_N / 2; x < MAX_N / 2; x++) {
            !x && y && printf("%3d", y);
            if (!y) {
                printf("%3d", x);
            } else {
                if (Point::x_y_axis[x + (MAX_N / 2)][y + (MAX_N / 2)]) {
                    printf("%3c", '*');
                }
                else if (x) printf("%3c", ' ');
            }
        }
        putchar(10);
    }
    return p1;
}

ostream &operator<<(ostream &out, const Point &p1) {
    out << "p("  << p1.x << ", " << p1.y << ")" << endl;
    return out;
}

int main() {
    Point::init_x_y_axis();
    Point p1(5, 6), p2(3, 6), p3(6, 9), p4(-2, -4);
    cout << p1 << p2 << p3 << p4 << endl;
    //^运算符将每个类中的成员属性x,y输出到一个坐标轴中
    //^1时打印出这个坐标轴
    p1^p2^p3^p4^1;
    return 0;
}
