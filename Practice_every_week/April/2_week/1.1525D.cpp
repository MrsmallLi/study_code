/*************************************************************************
	> File Name: 1.1525D.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Apr 2025 06:33:49 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

#define MAX_N 5000
int dp[MAX_N + 5][MAX_N + 5];
vector<int> ind[2];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        ind[a].push_back(i);
    }
    int m = ind[1].size();
    int k = ind[0].size();
    /*
    for (int i = 0; i < m; i++) {
        cout << ind[1][i] << " ";
    }
    cout << endl;
    for (int i = 0; i < k; i++) {
        cout << ind[0][i] << " ";
    }
    */
    for (int i = 0; i <= k; i++) dp[0][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            if (i > j) continue;
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(ind[1][i - 1] - ind[0][j - 1]));
        }
    }
    cout << dp[m][k] << endl;
    return 0;
}
