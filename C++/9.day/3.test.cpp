/*************************************************************************
	> File Name: 3.test.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jun 2024 06:36:08 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100

int f[MAX_N + 5][10][4] = {0};
int mod = 1120938912;

int main() {
    int n, m;
    cin >> n >> m;
    f[1][1][0] = f[1][2][1] = f[1][2][2] = f[1][1][3] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j][0] = f[i - 1][j][0] + f[i - 1][j][1] + f[i - 1][j][2] + f[i - 1][j - 1][3];
            f[i][j][3] = f[i - 1][j - 1][0] + f[i - 1][j][1] + f[i - 1][j][2] + f[i - 1][j][3];
            if (j >= 2) {
            f[i][j][1] = f[i - 1][j - 1][0] + f[i - 1][j][1] + f[i - 1][j - 2][2] + f[i - 1][j - 1][3];
            f[i][j][2] = f[i - 1][j - 1][0] + f[i - 1][j - 2][1] + f[i - 1][j][2] + f[i - 1][j - 1][3];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) ans = (ans + f[n][m][i]) % mod;
    cout << ans << endl;
    return 0;
}
