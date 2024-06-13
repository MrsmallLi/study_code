/*************************************************************************
	> File Name: 636.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Jun 2024 03:00:20 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 100000

vector<int> fa(MAX_N + 5, 0);
vector<vector<int>> child(MAX_N + 5);

vector<int> ans(MAX_N + 5, 0);


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        fa[b] += 1;
        child[a].push_back(b);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (fa[i]) continue;
        q.push(i);
        ans[i] = 1;
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < child[now].size(); i++) {
            int num = child[now][i];
            fa[num] -= 1;
            if (fa[num]) continue;
            ans[num] = max(ans[now] + 1, ans[num]);
            q.push(num);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
