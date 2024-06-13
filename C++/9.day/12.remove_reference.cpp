/*************************************************************************
	> File Name: 12.remove_reference.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Jun 2024 12:34:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


template<typename T>
void func(T &&t) {
    //通过remove_reference，去掉T的引用获取到他的类型
    typedef typename remove_reference<T>::type a;
    if (is_same<a, int>::value) cout << "a type is int" << endl;
    if (is_same<a, char>::value) cout << "a type is char" << endl;
    if (is_same<a, double>::value) cout << "a type is double" << endl;
    if (is_same<a, float>::value) cout << "a type is float" << endl;
    if (is_same<a, string>::value) cout << "a type is string" << endl;
}
    




int main() {
    int a;
    string str = "hello";
    func(a);
    func(str);
    func('a');
    func(3.14);
    return 0;
}
