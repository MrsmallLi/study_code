/*************************************************************************
	> File Name: 1.add.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 May 2024 07:19:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define P(func) {\
    cout << #func "=" << func << endl;\
}

class No_defualt_Constructor {
public :
    No_defualt_Constructor() = delete;
    No_defualt_Constructor(double y) : y(y) {}
    double operator+(int x) { return x + y; }
    double y;
};


template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b){
    return a + b;
}

int main() {
    No_defualt_Constructor ndc = 3.4;
    cout << ndc + 4 << endl;
    P(add(ndc, 4));
    P(add(2, 3));
    P(add(5, 6));
    P(add<long long>(5, 1LL));
    P(add(1.3, 2));
    P(add(2, 1.3));
    P(add(500.12, 1000.98));
    string a = "123", b = "xyz";
    P(add(a, b));
    return 0;
}
