/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 10:03:58 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
using namespace std;

char arr[1005][1005] = {0};


int main() {
    int h, w;
    cin >> h >> w;
    bool flag = 1, black = false, no_color = false;
    int x_l = INT_MAX, y_l = INT_MAX, x_r = INT_MIN, y_r = INT_MIN;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char c;
            cin >> c;
            arr[i][j] = c;
            switch (c) {
                case '.' : continue;
                case '#' : {
                    x_l = min(x_l, j);
                    y_l = min(y_l, i);
                    x_r = max(x_r, j);
                    y_r = max(y_r, i);
                    black = true;
                } break;
                case '?' : {
                    no_color = true;
                } break;
            }
        }
    }
    if (flag && !black && no_color) cout << "Yes" << endl;
    for (int i = y_l; i <= y_r; i++) {
        for (int j = x_l; j <= x_r; j++) {
            if (arr[i][j] != '.') continue;
            flag = 0;
            break;
        }
        if (!flag) break;
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
