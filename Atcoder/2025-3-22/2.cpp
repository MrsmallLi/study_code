/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Mar 2025 08:05:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[20];

int main() {
    for (int i = 0; i < 7; i++) {
        int a;
        cin >> a;
        num[a] += 1;
    }
    int x = 0, y = 0;
    for (int i = 1; i <= 13; i++) {
        if (num[i] >= 3 && !x) {
            x = i;
        } 
        if (num[i] >= 2 && i != x) {
            y = i;
        }
    }
    if (x && y) {
       cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
