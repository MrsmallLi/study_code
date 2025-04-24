/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Mar 2025 09:45:20 PM CST
 ************************************************************************/


#include <iostream>
#include <set>
using namespace std;

typedef pair<int, int> PII;

struct Edge {
    int to, nxt;
} e[205];
int head[105], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

int n;
int dep[105];
set<int> f[105][2];
set<PII> ans;

void dfs(int fa, int ind, int d) {
    dep[ind] = d;
    f[ind][1].insert(ind);
    for (int p = head[ind]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == fa) continue;
        dfs(ind, to, d + 1);
        for (int a : f[to][1]) {
            for (int b : f[ind][1]) {
                int l = dep[a] + dep[b] - 2 * dep[ind] + 1;
                if (l <= 2) continue;
                if (a > b) ans.insert(PII(b, a));
                else ans.insert(PII(a, b));
            }
        }
        for (int a : f[to][0]) {
            for (int b : f[ind][0]) {
                int l = dep[a] + dep[b] - 2 * dep[ind] + 1;
                if (l <= 2) continue;
                if (a > b) ans.insert(PII(b, a));
                else ans.insert(PII(a, b));
            }
        }
        for (int x : f[to][1]) f[ind][0].insert(x);
        for (int x : f[to][0]) f[ind][1].insert(x);
    }
    return ;
}

int main() {
    int a, b;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(0, 1, 0);
    if (ans.size() % 2) {
        cout << "First" << endl;
        while (ans.size()) {
            PII x = *(ans.begin());
            cout << x.first << " " << x.second << endl;
            cin >> a >> b;
            if (a == -1 && b == -1) break;
            if (a > b) swap(a, b);
            ans.erase(ans.begin());
            ans.erase(ans.find(PII(a, b)));
        }
    } else {
        cout << "Second" << endl;
        while (ans.size()) {
            cin >> a >> b;
            if (a == -1 && b == -1) break;
            if (a > b) swap(a, b);
            ans.erase(ans.find(PII(a, b)));
            PII x = *(ans.begin());
            cout << x.first << " " << x.second << endl;
            ans.erase(ans.begin());
        }
    }
    return 0;
}

