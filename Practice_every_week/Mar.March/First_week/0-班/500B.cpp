/*************************************************************************
	> File Name: 500B.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Mar 2025 02:32:50 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 300

class My_Union {
public:
    My_Union(int n) : fa(n + 1) {
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


int p[MAX_N + 5];
string flag[MAX_N + 5];

int main() {
    int n;
    scanf("%d", &n);
    My_Union u(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 1; i <= n; i++) {
        cin >> flag[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            if (flag[i][j - 1] == '1') {
                u.merge(p[i], p[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (u.find(p[j]) == u.find(p[i]) && p[i] > p[j]) {
                swap(p[i], p[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        i != 1 && printf(" ");
        cout << p[i];
    }
    cout << endl;
    return 0;
}
