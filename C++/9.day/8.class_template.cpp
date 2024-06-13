/*************************************************************************
	> File Name: 8.class_template.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Jun 2024 03:18:44 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//利用模板创建一个模板类
template<typename T>
class A {
public : 
    A(int n = 10) : n(n) {
        this->arr = new T[n];
    }
    T &operator[](int ind) {
        if (ind < 0 || ind > n) return __end;
        return arr[ind];
    }
    void rand_arr() {
        for (int i = 0; i < n; i++) {
            int x = rand() % 100;
            arr[i] = x - (T)x / 10;
        }
        return ;
    }
    ~A() {
        delete arr;
    }
    template<typename U>
    friend ostream &operator<<(ostream &out, const A<U> &obj);
private :
    T *arr;
    int n;
    T __end;
};

template<typename T>
ostream &operator<<(ostream &out, const A<T> &obj) {
    for (int i = 0; i < obj.n; i++) {
        cout << obj.arr[i] << " ";
    }
    return out;
}


int main() {
    srand(time(0));
    //通过模板类创建对象时
    //需要确定模板类型中的模板参数类型
    A<int> a;
    a.rand_arr();
    A<double> b;
    b.rand_arr();
    cout << a << endl;
    cout << b << endl;
    return 0;
}
