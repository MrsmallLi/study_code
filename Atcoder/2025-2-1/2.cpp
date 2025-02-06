/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Feb 2025 08:30:43 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
int n, m;
string s[55], t[55];

bool check(int x, int y) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (s[x + i][y + j] == t[i][j]) continue;
            return 0;
        }
    }
    return 1;
}


int main() {
    cin >> n >> m;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> t[i];
    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < n - m + 1; j++) {
            if (!check(i, j)) continue;
            a = i + 1, b = j + 1;
            break;
        }
    }
    cout << a << " " << b << endl;

    return 0;
}
