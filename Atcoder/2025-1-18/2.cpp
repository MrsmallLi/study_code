/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Jan 2025 08:16:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long f[105] = {0};


int main() {
    long long x;
    cin >> x;
    for (int i = 0; i < 50; i++) f[i] = i;
    int n = 1;
    long long ans = 1;
    while (1) {
        ans *= f[n];
        if (ans == x) break;
        n++;
    }
    cout << n << endl;
    return 0;
}
