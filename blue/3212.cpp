/*************************************************************************
	> File Name: 3212.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Apr 2025 11:51:46 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int arr[15][15];
int f[8][2] {
    {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
    {1, 0}, {1, -1}, {0, -1}, {-1, -1}
};
int flag[15][15];
vector<int> ans;
vector<int> ret;
int n, k;
int ans_size;
int g = 0;
int step[15][15][15][15];

void dfs(int x, int y) {
    if (g) return ;
    if ((x == n) && (y == n)) {
        if (ans.size() == n * n - 1) {
            ret = ans;
            g = 1;
        }
        return ;
    }
    int num = (arr[x][y] + 1) % k;
    for (int i = 0; i < 8; i++) {
        int a = x + f[i][0];
        int b = y + f[i][1];
        if (a <= 0 || a > n) continue;
        if (b <= 0 || b > n) continue;
        if (flag[a][b]) continue;
        if (arr[a][b] != num) continue;
        if (i % 2 && (step[a][y][x][b] || step[x][b][a][y])) continue;
        flag[x][y] = 1;
        step[x][y][a][b] = 1;
        ans.push_back(i);
        dfs(a, b);
        ans.pop_back();
        flag[x][y] = 0;
        step[x][y][a][b] = 0;
    }
    return ;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    flag[1][1] = 1;
    dfs(1, 1);
    if (arr[1][1] == 0 && ret.size() != 0) {
        for (int i = 0; i < ret.size(); i++) cout << ret[i];
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
