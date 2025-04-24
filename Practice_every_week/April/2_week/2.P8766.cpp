/*************************************************************************
	> File Name: 2.P8766.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 14 Apr 2025 07:53:39 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define int long long
int num[40];
int dp[40][8][2];

int dfs(int ind, int state, int pre) {
    if (ind == 0) {
        return (state == 7);
    } 
    if (dp[ind][state][pre]) return dp[ind][state][pre];
    int max_num = pre ? num[ind] : 1;
    int ret = 0;
    for (int i = 0; i <= max_num; i++) {
        if (i == 0) {
            //(0, 0)
            ret += dfs(ind - 1, state, pre && (i == max_num));
            if (state < 6) continue;
            //(0, 1)
            ret += dfs(ind - 1, state | 1, pre && (i == max_num));
        } else {
            ret += dfs(ind - 1, state | 4, pre && (i == max_num));
            ret += dfs(ind - 1, state | 2, pre && (i == max_num));
        }
    }
    return dp[ind][state][pre] = ret;
}

void solve() {
    memset(num, 0, sizeof(num));
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    int ind = 0;
    while (n) {
        num[++ind] = n & 1;
        n >>= 1;
    }
    dfs(ind, 0, 1);
    cout << dp[ind][0][1] * 3 << endl;
    return ;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
