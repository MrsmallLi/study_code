/*************************************************************************
	> File Name: 360.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Apr 2025 04:01:00 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
using namespace std;
#define int long long

int a[15][15];
int dp[20][15][15][15][15];

int VAL(int i, int j, int k, int  l) {
    return a[k][l] - a[k][j - 1] - a[i - 1][l] + a[i - 1][j - 1];
}
int S(int x) { return x * x; }

int32_t main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            for (int k = i; k <= 8; k++) {
                for (int l = j; l <= 8; l++) {
                    dp[1][i][j][k][l] = S(VAL(i, j, k, l));
                }
            }
        }
    }
    for (int t = 2; t <= n; t++) {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                for (int k = i; k <= 8; k++) {
                    for (int l = j; l <= 8; l++) {
                        int ans = INT_MAX;
                        for (int c = j; c < l; c++) {
                            int val1 = dp[1][i][j][k][c] + dp[t - 1][i][c + 1][k][l];
                            int val2 = dp[t - 1][i][j][k][c] + dp[1][i][c + 1][k][l];
                            ans = min(ans, min(val1, val2));
                        }
                        for (int c = i; c < k; c++) {
                            int val1 = dp[1][i][j][c][l] + dp[t - 1][c + 1][j][k][l];
                            int val2 = dp[t - 1][i][j][c][l] + dp[1][c + 1][j][k][l];
                            ans = min(ans, min(val1, val2));
                        }
                        dp[t][i][j][k][l] = ans;
                    }
                }
            }
        }
    }
    cout << dp[n][1][1][8][8] << endl;
    return 0;
}
