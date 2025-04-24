/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Mar 2025 02:59:24 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100000

int door[MAX_N + 5];

vector<vector<int>> key(MAX_N + 5);

class My_Union {
public :
    My_Union(int n) : fa(2 * n + 1) {
        for (int i = 1; i <= 2 * n; i++) fa[i] = i;
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



int main() {
    int n, m;
    cin >> n >> m;
    My_Union u(m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", door + i);
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        while (x--) {
            int a;
            cin >> a;
            key[a].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        int a = key[i][0];
        int b = key[i][1];
        if (door[i] == 1) {
            //a, b开关不动
            u.merge(a, b);
            //a, b开关打开
            u.merge(a + m, b + m);
        } else {
            u.merge(a, b + m);
            u.merge(a + m, b);
        }
    }
    int flag = 1; 
    for (int i = 1; i <= m; i++) {
        if (u.find(i) != u.find(i + m)) continue;
        flag = 0; 
        break;
    }
    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO"  << endl;
    }

    return 0;
}
