/*************************************************************************
	> File Name: 1.operator_overload.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Apr 2024 03:46:32 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

class Point {
public :
    Point() : x(0), y(0), output_width(0) {}
    Point(int x, int y) : x(x), y(y), output_width(0) {}
private :
    int x, y;
    int output_width;
    //利用友元进行解决私有成员属性的访问问题
    friend ostream &operator<<(ostream &out, const Point &p);
    friend int operator*(const Point &, const Point &);
    friend Point operator+(const Point &, int );
    friend double operator*(const Point &, double );
    friend double operator*(double , const Point &);
    friend Point &operator-(Point &, int x) ;
    friend Point &operator-(Point &, Point &) ;
    friend Point &operator-(Point &, const char *) ;
};
//ostream类型就像cout的对象的类型
//加上const为了同时支持const和非const限定的对象
ostream &operator<<(ostream &out, const Point &p) {
    out << "("  << p.x << ", " << p.y << ")";
    return out; 
}

int operator*(const Point &p1, const Point &p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

Point operator+(const Point &p1, int x) {
    Point p(p1.x + x, p1.y + x);
    return p;
}

double operator*(const Point &p1, double x) {
    return p1.x * x + p1.y * x;
}

double operator*(double x, const Point &p1) {
    //这里他调用的就是上面运算符重载的方法
    return p1 * x;
}

Point &operator-(Point &p, int x) {
    p.output_width = x; 
    return p;
}

Point &operator-(Point &p1, Point &p2) {
    char str[100] = {0};
    snprintf(str, 99, "(%%%dd, %%%dd)", p1.output_width, p1.output_width);
    printf(str, p2.x, p2.y);
    return p1;
}

Point &operator-(Point &p, const char *s) {
    printf("%s", s);
    return p;
}

Point &operator^(Point &p1, const Point &p2) {
     
    return p1;
}

Point &operator^(Point &p1, int x) {

    return p1;
}

int main() {
    Point p1(5, 6), p2(3, 6), p3(6, 9), p4(10, 12);
    //cout他也不认识我们创建的Point类
    //如果要对cout进行对p1进行输出
    //那么我们就要对<<这个左移运算符进行重载
    cout << p1 << endl;
    //这里对运算符的重载可以不用实现和我一样的，可以通过自己的想象然后来实现
    //然后实现的结果和自己的想象的需要是一样的结果
    cout << p1 * p2 << endl;
    cout << p1 * 2.3 << endl;
    cout << 2.3 * p1 << endl;
    cout << p1 + 5 << endl;
    //实现效果
    //p1 - 6设置输出的位宽为6
    //- p2 输出p2的值,并且输入的位宽为p1的位宽
    //- "\n" 换行
    p1 - 6 - p2 - "\n";
    //^运算符将每个类中的成员属性x,y输出到一个坐标轴中
    //^1时打印出这个坐标轴
    p1^p2^p3^p4^1;
    return 0;
}
