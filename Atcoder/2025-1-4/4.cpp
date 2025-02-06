/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 09:16:05 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
#include <queue>
using namespace std;
#define MAX_N 1000

class Point{
public :
    Point(int x, int y, int c, int step) : x(x), y(y), c(c), step(step) {}
    int x, y, c, step;
};

int arr[MAX_N + 5][MAX_N + 5] = {0};
int val[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int bfs(int s_x, int s_y, int e_x, int e_y, int h, int w) {
    queue<Point> num;
    arr[s_x][s_y] = -1;
    for (int i = 0; i < 4; i++) {
        int d_x = s_x + val[i][0];
        int d_y = s_y + val[i][1];
        if (d_x < 1 || d_x > h) continue;
        if (d_y < 1 || d_y > h) continue;
        if (arr[d_x][d_y] == -1) continue;
        int c;
        if (val[i][0]) c = 0;
        else c = 1;
        arr[d_x][d_y] = 1;
        num.push(Point(d_x, d_y, c, 1));
    
    /*
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            printf("%2d ", arr[i][j]);
        }
        cout << endl;
    }
    */
    while (!num.empty()) {
        Point now = num.front();
        num.pop();
        for (int i = (now.c ? 2 : 0), j = 0; j < 2; j++, i++) {
            int d_x = now.x + val[i][0];
            int d_y = now.y + val[i][1];
            printf("x = %d, y = %d, step = %d\n, c = %d\n", d_x, d_y, arr[d_x][d_y], now.c);
            if (d_x < 1 || d_x > h) continue;
            if (d_y < 1 || d_y > w) continue;
            if (arr[d_x][d_y]) continue;
            cout << "yes" << endl;
            arr[d_x][d_y] = now.step + 1;
            printf("x = %d, y = %d, step = %d\n", d_x, d_y, arr[d_x][d_y]);
            if (d_x == e_x && d_y == e_y) return now.step + 1;
            int c = !now.c;
            num.push(Point(d_x, d_y, c, now.step + 1));
        }
    }
    return -1;
}


int main() {
    int h, w;
    cin >> h >> w;
    int s_x, s_y, e_x, e_y;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char a;
            cin >> a;
            switch(a) {
                case 'S': {
                    s_x = i, s_y = j;
                }; break;
                case 'G': {
                    e_x = i, e_y = j;
                } break;
                case '#': {
                    arr[i][j] = -1;
                } break;
            }
        }
    }
    cout << bfs(s_x, s_y, e_x, e_y, h, w) << endl;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            printf("%2d ", arr[i][j]);
        }
        cout << endl;
    }
    return 0;
}
