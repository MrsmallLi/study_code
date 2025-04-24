/*************************************************************************
	> File Name: 3+.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 09:54:22 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 200000

vector<vector<int>> fa(MAX_N + 5, vector<int>(0));

int main() {
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int flag = 1;
        for (int i = 0; i < fa[a].size(); i++) {
            if (fa[a][i] != b) continue;
            flag = 0;
            break;
        }
        for (int i = 0; flag && i < fa[b].size(); i++) {
            if (fa[b][i] != a) continue;
            flag = 0;
            break;
        }
        if (!flag || a == b) {
            ans += 1;
            flag = 0;
        }
        if (flag) {
            fa[a].push_back(b);
            fa[b].push_back(a);
        }
    }
    cout << ans << endl;

    return 0;
}
