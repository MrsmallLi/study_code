/*************************************************************************
	> File Name: 11.reference_folding.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jun 2024 11:51:49 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define TEST(func, n) {\
    printf("%s(%s) ", #func, #n);\
    func(n);\
}

template<typename T>
void func(T &&a) {
    //假如T为int & 那么a的类型就为int &&&然后通过折叠得到为int &
    if (is_same<T &, decltype(a)>::value) {
        cout << " is left" << endl;
    //假如T为int && 那么a的类型就为int&& &&然后通过折叠得到为int &&
    } else if (is_same<T &&, decltype(a)>::value) {
        cout << " is right" << endl;
    } else {
        cout << " is a type" << endl;
    }
    return ;
}




int main() {
    int n = 123; 
    int& l = n;
    int&& r = 123;
    TEST(func, n); //n为左值, T类型就为int &
    TEST(func, l); //l为左值, T类型就为int &
    TEST(func, r); //r为左值, T类型就为int &
    TEST(func, 123); //123为右值, T类型就为int &&
    TEST(func, move(n)); //move(n)为右值, T类型就为int &&
    return 0;
}
