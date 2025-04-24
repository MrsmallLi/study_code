/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Apr 2025 08:02:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int a;
    cin >> a;
    if (400 % a == 0) {
        cout << 400 / a << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
