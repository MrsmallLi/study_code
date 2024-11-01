/*************************************************************************
	> File Name: 121.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Oct 2024 11:24:03 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}


int main() {
    int a, b;
    cin >> a >> b;
    cout << a * b / gcd(a, b) << endl;


    return 0;
}
