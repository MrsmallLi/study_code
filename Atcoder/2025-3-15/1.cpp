/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Mar 2025 08:03:35 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    double a;
    cin >> a;
    if (a >= 38.0) {
        cout << 1 << endl;
    } else if (a < 38.0 && a >= 37.5) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
    
    return 0;
}
