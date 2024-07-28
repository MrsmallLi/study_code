/*************************************************************************
	> File Name: 44.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Jun 2024 01:18:58 PM CST
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
#define MAX_N 1000

int dp[MAX_N + 5][MAX_N + 5] = {0};

int main() {
    char a[MAX_N + 5] = {0}, b[MAX_N + 5] = {0};
    cin >> a + 1 >> b + 1;
    int n = strlen(a + 1), m = strlen(b + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (a[i] == b[j]));
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
