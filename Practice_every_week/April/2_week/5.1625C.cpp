/*************************************************************************
	> File Name: 5.1625C.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 17 Apr 2025 08:16:48 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 500

int a[MAX_N + 5], b[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];
int n, t, k;


int main() {
    cin >> n >> t >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    a[n] = t;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i && j <= k; j++) {
            for (int s = 0; s < i; s++) {
                if (i - s - 1 > j) continue;
                dp[i][j] = min(dp[i][j], dp[s][j - (i - s - 1)] + b[s] * (a[i] - a[s]));
            }
        }
    }
    /*
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i && j <= k; j++) {
            printf("dp[%d][%d] = %d, ", i, j, dp[i][j]);
        }
        cout << endl;
    }
    */
    int ans;
    memset(&ans, 0x3f, sizeof(int));
    for (int i = 0; i <= n; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
