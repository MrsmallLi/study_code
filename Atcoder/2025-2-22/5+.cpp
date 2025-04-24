/*************************************************************************
	> File Name: 5.E.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 日  2/23 09:58:49 2025
 ************************************************************************/

#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct Data {
    int f, t, c;
};

int n;
char g[105][105];
int dis[105][105];
map<char, set<int>> fc[105], tc[105];

void bfs() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = -1;
            if (g[i][j] == '-') continue;
            tc[i][g[i][j]].insert(j);
            fc[j][g[i][j]].insert(i);
        }
    }
    queue<Data> q;
    for (int i = 1; i <= n; i++) {
        q.push({i, i, 0}), dis[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || g[i][j] == '-') continue;
            q.push({i, j, 1}), dis[i][j] = 1;
        }
    }
    while (!q.empty()) {
        Data cur = q.front();
        q.pop();
        for (auto x : fc[cur.f]) {
            char ch = x.first;
            if (tc[cur.t].find(ch) == tc[cur.t].end()) continue;
            for (auto f : x.second) {
                for (auto t : tc[cur.t][ch]) {
                    if (dis[f][t] != -1) continue;
                    q.push({f, t, cur.c + 2}), dis[f][t] = cur.c + 2;
                }
            }
        }
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%s", g[i] + 1);
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dis[i][j] << " \n"[j == n];
        }
    }
    return 0;
}
