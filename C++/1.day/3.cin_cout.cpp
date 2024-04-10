/*************************************************************************
	> File Name: 2.cin_cout.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Apr 2024 09:27:46 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    //使用cin时，也不用对变量进行取地址了
    //也不用使用格式占位符
    cin >> n;
    //在这里使用cout
    //就不像使用printf还需要使用格式占位符了
    cout << "hello world " << "n = " << n << endl;
    return 0;
}

