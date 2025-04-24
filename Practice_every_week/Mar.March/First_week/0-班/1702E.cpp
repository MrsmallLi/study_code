/*************************************************************************
	> File Name: 1873H.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Mar 2025 07:48:02 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


class My_Union {
public :
    My_Union(int n) : fa(n + 1, 0) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }

    int find(int x) {
        return fa[x] = (fa[x] == x ? x : find(fa[x]));
    }
    
    void merge(int a, int b) {
        int aa = find(a), bb = find(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        return ;
    }
    vector<int> fa;
};


void solve() {
    int n;
    cin >> n;
    vector<int> num(n + 1, 0);
    vector<pair<int, int>> temp;
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        num[a] += 1;
        num[b] += 1;
        temp.push_back({a, b});
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 2) continue;
        cout << "NO" << endl;
        return ;
    }
    My_Union mu(2 * n);
    int flag = 1;
    for (auto x : temp) {
        int u = x.first;
        int v = x.second;
        if (mu.find(u) == mu.find(v)) {
            flag = 0;
            break;
        }
        mu.merge(u, v + n);
        mu.merge(v, u + n);
    }
    if (!flag) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
    return 0;
}
