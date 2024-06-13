/*************************************************************************
	> File Name: 641.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Jun 2024 07:54:51 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> fa(n + 1, 0);
    vector<vector<int>> child(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        child[x].push_back(y);
        fa[y] += 1;
    }
    auto cmp = [&](int a, int b) { return a > b; };
    priority_queue<int, vector<int>,decltype(cmp)> q(cmp);
    vector<int> flag(n + 1, 0);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (fa[i]) continue;
        q.push(i);
        flag[i] = 1;
    }
    while (!q.empty()) {
        int num = q.top();
        ans.push_back(num);
        q.pop();
        for (int i = 0; i < child[num].size(); i++) {
            int n = child[num][i];
            fa[n] -= 1;
            if (fa[n]) continue;
            flag[n] = 1;
            q.push(n);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (flag[i]) continue;
        ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); i++) {
        i && cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
