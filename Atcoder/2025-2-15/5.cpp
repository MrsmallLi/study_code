/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 08:55:27 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}


int main() {
    int a, b;
    cout << gcd(a, b) << endl;
    return 0;
}
