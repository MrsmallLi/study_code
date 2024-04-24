/*************************************************************************
	> File Name: 9.special_object.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Apr 2024 05:30:31 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Array_Object {
public :
    int operator[](int ind) {
        return 2 * ind;
    }
};

class Function_Object {
public :
    int operator()(int x) {
        return 2 * x; 
    }
};

class Point {
public :
    Point(int x, int y) : x(x), y(y){
        printf("x = %d, y = %d\n", x, y);
    }
    int x, y;
};

class Point_Object {
public :
    Point_Object() : p(new Point(rand() % 100, rand() % 100)) {}
    Point *operator->() {
        return p; 
    }
    ~Point_Object() {
        delete p;
    }
private :
    Point *p;
};

int main() {
    srand(time(0));
    Array_Object arr;
    Function_Object fun;
    Point_Object p;
    cout << p->x << " " << p->y << endl;
    for (int i = 0; i < 10; i++) {
        cout << "arr[" << i << "]" << arr[i] << endl;
    }
    for (int i = 0; i < 10; i++) {
        cout << "fun(" << i << ")" << fun(i) << endl;
    }
    return 0;
}
