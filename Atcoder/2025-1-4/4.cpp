/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 09:16:05 PM CST
 ************************************************************************/

#include<iostream>
#include <climits>
using namespace std;

int num[1005][1005] = {0};
int s_x, s_y, e_x, e_y;
int val[1005][1005] = {0};
int n, m;

void bfs(int x, int y, int step, int flag) {
    if (num[x][y] > step && num[x][y] != -1) {
        num[x][y] = step;
    } else {
        return ;
    }
    if (flag == -1) {
        if (x + 1 <= n) bfs(x + 1, y, step + 1, 0);
        if (x - 1 >= 1) bfs(x - 1, y, step + 1, 0);
        if (y + 1 <= m) bfs(x, y + 1, step + 1, 1);
        if (y - 1 >= 1) bfs(x, y - 1, step + 1, 1);
    } else if (flag == 0) {
        if (y + 1 <= m) bfs(x, y + 1, step + 1, 1);
        if (y - 1 >= 1) bfs(x, y - 1, step + 1, 1);
    } else if (flag == 1) {
        if (x + 1 <= n) bfs(x + 1, y, step + 1, 0);
        if (x - 1 >= 1) bfs(x - 1, y, step + 1, 0);
    }
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char a;
            cin >> a;
            switch (a) {
                case '.': {
                    num[i][j] = INT_MAX;
                } break;
                case '#': {
                    num[i][j] = -1;
                } break;
                case 'G': {
                    e_x = i;
                    e_y = j;
                    num[i][j] = INT_MAX;
                } break;
                case 'S': {
                    s_x = i;
                    s_y = j;
                    num[i][j] = INT_MAX;
                }
            }
        }
    }
    bfs(s_x, s_y, 0, -1);
    if (num[e_x][e_y] != INT_MAX) {
        cout << num[e_x][e_y] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
