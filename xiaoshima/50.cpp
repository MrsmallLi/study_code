/*************************************************************************
	> File Name: 50.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Oct 2024 12:30:38 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b > a) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    if (c > a) {
        a = a + c;
        c = a - c;
        a = a - c;
    }
    cout << a << endl;
    return 0;
}
