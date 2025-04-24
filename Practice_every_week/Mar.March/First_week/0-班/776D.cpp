/*************************************************************************
	> File Name: 776DD.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 28 Feb 2025 04:33:41 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100000


int door[MAX_N + 5];
int m;
vector<vector<int>> key(MAX_N + 5);

vector<int> fa(2 * MAX_N + 5);


int find(int x) {
    return fa[x] = (fa[x] == x ? x : find(fa[x]));
}

void merge(int a, int b) {
    int aa = find(a), bb = find(b);
    if (aa == bb) return ;
    fa[aa] = bb;
    return ;
}



int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", door + i);
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        while (x--) {
            int temp;
            scanf("%d", &temp);
            key[temp].push_back(i);
        }
    }
    for (int i = 1; i <= 2 * m; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int a = key[i][0];
        int b = key[i][1];
        if (door[i] == 1) {
            merge(a + m, b + m);
            merge(a, b);
        } else {
            merge(a + m, b);
            merge(a, b + m);
        }
    }
    int flag = 1;
    for (int i = 1; i <= m; i++) {
        if (fa[i] != fa[i + m]) continue;
        flag = 0;
        break;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
