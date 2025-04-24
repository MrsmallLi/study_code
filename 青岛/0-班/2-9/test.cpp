/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 02:39:17 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
int a[10], b[10];

void output(int k) {
    vector<vector<int>> zu;
    for (int i = 0; i <= k; i++) zu.push_back(vector<int>());
    for (int i = 1; i <= n; i++) {
        zu[b[i]].push_back(i);
    }
    /*
    for (int i = 1; i <= k; i++) {
        for (auto x : zu[i]) cout << x;
        cout << " ";
    }
    cout << endl;
    */
    return ;
}

void dfs2(int ind, int n, int k) {
    if (ind > n) {
        output(k);
        return ;
    }
    if (b[ind] != 0) {
        dfs2(ind + 1, n, k);
        return ;
    }
    for (int i = 1; i <= k; i++) {
        b[ind] = i;
        dfs2(ind + 1, n, k);
    }
    return ;
}

void solve(int k) {
    memset(b, 0, sizeof(b));
    for (int i = 0; i < k; i++) {
        b[a[i]] = i + 1;
    }
    dfs2(1, n, k);
    return ;
}

void dfs1(int k, int ind, int n, int m) {
    if (k == m) {
        solve(k);
        return ;
    }
    for (int i = ind; i <= n; i++) {
        a[k] = i;
        dfs1(k + 1, i + 1, n, m);
    }
    return ;
}

int main() {
    cin >> n;
    for (int k = 1; k <= n; k++) {
        dfs1(0, 1, n, k);
    }
    return 0;
}
