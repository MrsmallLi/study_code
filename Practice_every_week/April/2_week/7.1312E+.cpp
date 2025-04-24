/*************************************************************************
	> File Name: 7.1312E.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Apr 2025 04:27:05 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 500

int n;
int a[MAX_N + 5];
int num[MAX_N + 5][MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];

int main() {
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) num[i][i] = a[i], dp[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; len + i - 1 < n; i++) {
            int j = len + i - 1;
            for (int x = i; x < j; x++) {
                if (dp[i][x] + dp[x + 1][j] < dp[i][j]) {
                    dp[i][j] = dp[i][x] + dp[x + 1][j];
                }
                if (num[i][x] == num[x + 1][j] && num[i][x] != 0) {
                    num[i][j] = num[i][x] + 1;
                    dp[i][j] = 1;
                }
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
