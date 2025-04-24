/*************************************************************************
	> File Name: P1541.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Apr 2025 04:30:01 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 350

int arr[MAX_N + 5];
int dp[45][45][45];
int cnt[10];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1, a; i <= m; i++) {
        cin >> a;
        cnt[a] += 1;
    }
    //dp[0][0][0] = arr[1];
    for (int a = 0; a <= cnt[1]; a++) {
        for (int b = 0; b <= cnt[2]; b++) {
            for (int c = 0; c <= cnt[3]; c++) {
                for (int d = 0; d <= cnt[4]; d++) {
                    int s = a + 2 * b + 3 * c + 4 * d + 1;
                    int ans = dp[b][c][d];
                    if (b) ans = max(ans, dp[b - 1][c][d]);
                    if (c) ans = max(ans, dp[b][c - 1][d]);
                    if (d) ans = max(ans, dp[b][c][d - 1]);
                    dp[b][c][d] = ans + arr[s];
                }
            }
        }
    }
    cout << dp[cnt[2]][cnt[3]][cnt[4]] << endl;
    return 0;
}
