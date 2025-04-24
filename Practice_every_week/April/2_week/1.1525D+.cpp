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
int dp[MAX_N + 5];
vector<int> ind[2];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
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
    dp[0] = 0;
    for (int j = 1; j <= k; j++) {
        for (int i = min(m, j); i >= 1; i--) {
            dp[i] = min(dp[i], dp[i - 1] + abs(ind[1][i - 1] - ind[0][j - 1]));
        }
    }
    cout << dp[k] << endl;
    return 0;
}
