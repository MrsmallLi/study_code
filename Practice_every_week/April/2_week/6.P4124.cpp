/*************************************************************************
	> File Name: 6.P4124.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Apr 2025 04:02:39 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define int long long
int num[20];
int dp[15][11][11][2][2][2][2];

int dfs(int ind, int pre_1, int pre_2, int state, int s4, int s8, int lim) {
    if (s4 && s8) return 0;
    if (ind < 0) {
        return (state && (!s4 || !s8));
    }
    if (dp[ind][pre_1][pre_2][state][s4][s8][lim]) return dp[ind][pre_1][pre_2][state][s4][s8][lim];
    int max_num = lim ? num[ind] : 9;
    //int num = (ind == len - 1) ? 1 : 0;
    int ret = 0;
    for (int i = 0; i <= max_num; i++) {
        ret += dfs(ind - 1, i, pre_1, state || (i == pre_1 && i == pre_2), s4 || (i == 4), s8 || (i == 8), lim && (i == max_num));
    }
    return dp[ind][pre_1][pre_2][state][s4][s8][lim] = ret;
}

int find(int n) {
    if (n < 1e10) return 0;
    memset(num, 0, sizeof(num));
    memset(dp, 0, sizeof(dp));
    int len = 0;
    while (n) {
        num[len++] = n % 10;
        n /= 10;
    }
    int ans = 0;
    for (int i = 1; i <= num[len - 1]; i++) {
        ans += dfs(len - 2, i, -1, 0, i == 4, i == 8, i == num[len - 1]);
    }
    return ans;
}

int32_t main() {
    int l, r;
    cin >> l >> r;
    int r_ans = find(r);
    int l_ans = find(l - 1);
    //cout << r_ans << endl;
    //cout << l_ans << endl;
    cout << r_ans - l_ans << endl;
    return 0;
}
