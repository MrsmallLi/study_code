/*************************************************************************
	> File Name: P2392.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jun 2024 05:40:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_S 10
#define MAX_T 60
#define MAX_NUM 99999999
int s[MAX_S + 5] = {0};
int t[MAX_S + 5][MAX_T + 5] = {0};
int ans = 0;

void dfs(int k, int i, int l, int r) {
    if (k == s[i]) {
        ans = min(ans, max(l , r));
        return ;
    }
    l += t[i][k];
    dfs(k + 1, i, l, r);
    l -= t[i][k];
    r += t[i][k];
    dfs(k + 1, i, l, r);
    r -= t[i][k];
    return ;
}



int main() {
    for (int i = 0; i < 4; i++) cin >> s[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < s[i]; j++) {
            cin >> t[i][j];
        }
    }
    int total = 0;
    for (int i = 0; i < 4; i++) {
        ans = MAX_NUM;
        dfs(0, i, 0, 0);
        total += ans;
    }
    cout << total << endl;
    return 0;
}
