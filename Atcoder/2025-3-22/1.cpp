/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Mar 2025 08:02:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;



int main() {
    int n;
    cin >> n;
    if (n & 1) {
        int num = (n + 1) / 2;
        for (int i = 1; i <= n; i++) {
            if (num == i) {
                cout << "=";
            } else {
                cout << "-";
            }
        }
    } else {
        int num = n / 2;
        for (int i = 1; i <= n; i++) {
            if (i == num || i == (num + 1)) {
                cout << "=";
            } else {
                cout << "-";
            }
        }
    }
    cout << endl;
    return 0;
}
