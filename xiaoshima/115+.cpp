/*************************************************************************
	> File Name: 115+.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Oct 2024 12:58:15 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;



int main() {
    long long n;
    cin >> n;
    long long num = 0, x = n;
    while (x) {
        num *= 10;
        num += x % 10;
        x /= 10;
    }
    if (num == n) cout << "YES" << endl;
    else cout << "NO" << endl;
}
