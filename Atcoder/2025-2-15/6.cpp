/*************************************************************************
	> File Name: 6.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 09:08:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


#define MAX_N 200000

int a[MAX_N + 5], n;
int dp[MAX_N + 5], len[MAX_N + 5], ans = 0;

int main() {
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (q--) {
        int r, x;
        cin >> r >> x;
        for (int i = 1; i <= r; i++) {
            if (a[i] > x) continue;
                dp[i] = lower_bound(len, len + ans + 1, a[i]) - len;
                len[dp[i]] = a[i];
            ans = max(dp[i], ans);
        }
        cout << ans << endl;
    }
    return 0;
}
