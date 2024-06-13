/*************************************************************************
	> File Name: 4.test.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Jun 2024 03:50:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
    cout << "add function : " << sizeof(T) << endl;
    return a + b;
}

template<>
int add(int a, int b) {
    return a + b + 2;
}

template<typename T>
class Array{
public : 
    Array(int n) : n(n) {
        this->arr = new T[n];
    }
    T &operator[](int ind) {
        if (ind < 0 || ind >= 0) return this->__end;
        return this->arr[ind];
    }
    template<typename U>
    friend ostream &operator<<(ostream &out, const Array<U> &a);
private :
    T *arr;
    T __end;
    int n;
};

template<typename T>
ostream &operator<<(ostream &out, const Array<T> &a) {
    for (int i = 0; i < a.n; i++) {
        i && out << " ";
        out << a.arr[i];
    }
    return out;
}


int main() {
    cout << add(2, 3) << endl;
    cout << add(1.2, 3.4) << endl;
    Array<int> a(10);
    Array<double> b(10);
    cout << a << endl;
    cout << b << endl;
    return 0;
}
