/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 09:41:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n, a, b;
    cin >> n;
    int flag = 1;
    cin >> a >> b;
    int c = a / gcd(a, b);
    int d = b / gcd(a, b);
    a = b;
    for (int i = 3; i <= n; i++) {
        cin >> b;
        if (c != (a / gcd(a, b)) || d != (b / gcd(a, b))) {
            flag = 0;
            break;
        }
        a = b;
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
