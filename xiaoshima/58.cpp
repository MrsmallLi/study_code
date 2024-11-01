/*************************************************************************
	> File Name: 58.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 25 Oct 2024 03:39:34 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

void is_a_triangle(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    if (a + b < c) {
        cout << "not a triangle" << endl;
        return ;
    }
    if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    is_a_triangle(a, b, c);
    return 0;
}
