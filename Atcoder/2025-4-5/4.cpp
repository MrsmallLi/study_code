/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Apr 2025 08:52:18 PM CST
 ************************************************************************/

#include <iostream>
#include <deque>
#include <vector>
#include <climits>
using namespace std;

#define MAX_N 1000

struct Point {
public :
    int x, y;
};

string str[MAX_N + 5];
int f[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    A -= 1;
    B -= 1;
    C -= 1;
    D -= 1;
    deque<Point> dq;
    dq.push_back({A, B});
    vector<vector<int>> vis(MAX_N + 5, vector<int>(MAX_N + 5, INT_MAX));
    vis[A][B] = 0;
    while (!dq.empty()) {
        Point now = dq.front();
        int spend = vis[now.x][now.y];
        dq.pop_front();
        if (now.x == C && now.y == D) {
            cout << spend << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int dx = now.x + f[i][0];
            int dy = now.y + f[i][1];
            if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
            if (str[dx][dy] == '#') continue;
            if (spend >= vis[dx][dy]) continue;
            vis[dx][dy] = spend;
            dq.push_front({dx, dy});
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= 2; j++) {
                int dx = now.x + j * f[i][0];
                int dy = now.y + j * f[i][1];
                if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
                if (vis[dx][dy] <= spend + 1) continue;
                vis[dx][dy] = spend + 1;
                dq.push_back({dx, dy});
            }
        }
    }
    return 0;
}
