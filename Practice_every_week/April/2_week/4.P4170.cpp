/*************************************************************************
	> File Name: 4.P4170.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Apr 2025 12:29:11 PM CST
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
#define MAX_N 50

string a;
int dp[MAX_N + 5][MAX_N + 5];



int main() {
    cin >> a; 
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; a[i]; i++) {
        dp[i][i] = 1;
    }
    int n = a.length();
    for (int len = 2; len <= n; len++)  {
        for (int i = 0; len + i - 1 < n; i++) {
            int j = len + i - 1;
            for (int x = i; x < j; x++) {
                dp[i][j] = min(dp[i][j], dp[i][x] + dp[x + 1][j]);
            }
            if (a[i] == a[j]) {
                dp[i][j] = min(dp[i][j], min(dp[i + 1][j], dp[i][j - 1]));
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
