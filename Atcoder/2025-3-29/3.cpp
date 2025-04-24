/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Mar 2025 08:16:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 200000

int fa[MAX_N + 5];

int find(int x) {
    return fa[x] = (fa[x] == x ? x : find(fa[x]));
}

void merge(int a, int b) {
    fa[find(a)] = fa[find(b)];
    return ;
}


int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (find(u) == find(v)) {
            ans += 1;
        } else {
            merge(u, v);
        }
    }
    cout << ans << endl;
    return 0;
}
