/*************************************************************************
	> File Name: C.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 09:30:21 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 200000

vector<vector<int>> fa(MAX_N + 5);


int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int flag = 1;
        for (int i = 0; i < fa[a].size(); i++) {
            if (fa[a][i] != b) continue;
            flag = 0; 
            break;
        }
        for (int i = 0; i < fa[b].size(); i++) {
            if (fa[b][i] != a) continue;
            flag = 0;
            break;
        }
        if (a == b || !flag) {
            ans += 1;
        } else {
            fa[a].push_back(b);
            fa[b].push_back(a);
        }
    }
    cout << ans << endl;
    return 0;
}
