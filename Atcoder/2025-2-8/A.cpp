/*************************************************************************
	> File Name: A.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 08:00:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a * b == c || a * c == b || b * c == a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
