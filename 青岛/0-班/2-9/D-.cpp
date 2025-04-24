/*************************************************************************
	> File Name: D-.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 11:10:57 AM CST
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int n;
int zu[15], arr[15];


void output(int k) {
    vector<vector<int>> out;
    for (int i = 0; i <= k; i++) out.push_back(vector<int>());
    for (int i = 1; i <= n; i++) {
        out[zu[i]].push_back(i);
    }
    for (int i = 1; i <= k; i++) {
        for (auto x : out[i]) {
            cout << x;
        }
        cout << " ";
    }
    cout << endl;
    return ;
}

void dfs2(int ind, int k) {
    if (ind > n) {
        output(k);
        return ;
    }
    if (zu[ind] != 0) {
        dfs2(ind + 1, k);
        return ;
    }
    for (int i = 1; i <= k; i++) {
        zu[ind] = i;
        dfs2(ind + 1, k);
    }
    return ;    
}

void solve(int k) {
    memset(zu, 0, sizeof(zu));
    for (int i = 0; i < k; i++) {
        zu[arr[i]] = i + 1;
    }
    dfs2(1, k);
    return ;
}

void dfs(int k, int ind, int m) {
    if (k == m) {
        solve(k);
        return ;
    }
    for (int i = ind; i <= n; i++) {
        arr[k] = i;
        dfs(k + 1, i + 1, m);
    }
    return ;
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dfs(0, 1, i);
    }
    return 0;
}
