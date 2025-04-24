/*************************************************************************
	> File Name: 112A.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 03:35:19 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

char lower(char x) {
    return x < 97 ? (x + 32) : x;
}

int fun(string a, string b) {
    for (int i = 0; a[i]; i++) {
        char x = lower(a[i]), y = lower(b[i]);
        if (x > y) return 1;
        if (x < y) return -1;
    }
    return 0;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << fun(a, b) << endl;
    return 0;
}
