/*************************************************************************
	> File Name: 434.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Nov 2024 05:43:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000

long long f[100000][3] = {0};


int main() {
    int n;
    cin >> n;
    f[1][0] = 1;
    f[1][1] = 0;
    f[1][2] = 1;
    f[2][0] = 1;
    f[2][2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i][0] = f[i - 1][2] + f[i - 2][2];
        if (i != n) f[i][1] = f[i - 1][0] + f[i - 1][2];
        f[i][2] = f[i - 1][0] + f[i - 2][0];
    }
    long long ans = f[n][0] + f[n][2];
    cout << ans << endl;
    return 0;
}
