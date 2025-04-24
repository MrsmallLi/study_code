/*************************************************************************
	> File Name: 3.Zuma.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 15 Apr 2025 08:59:21 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 500
int a[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];

int main() {
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = len + i - 1;
            if (a[i] == a[j]) {
                if (i + 1 == j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            } 
            for (int x = i; x < j; x++) {
                dp[i][j] = min(dp[i][j], dp[i][x] + dp[x + 1][j]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
