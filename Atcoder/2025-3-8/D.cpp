/*************************************************************************
	> File Name: D.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Mar 2025 08:43:03 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <climits>
using namespace std;
#define int long long

vector<vector<int>> arr(15);
int val[15][15];
int flag2[15];
int ans = INT64_MAX;
int n, m;

void dfs(int x, int num) {
    if (x == n) {
        ans = min(ans, num);
    }
    flag2[x] = 1;
    for (auto p : arr[x]) {
        if (flag2[p] == 1) continue ;
        dfs(p, num ^ val[x][p]);
        flag2[p] = 0;
    }
    return ;
}


int32_t main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        arr[u].push_back(v);
        arr[v].push_back(u);
        val[u][v] = c;
        val[v][u] = c;
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
