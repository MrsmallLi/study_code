/*************************************************************************
	> File Name: 47+.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Apr 2025 01:54:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define int long long

#define MAX_N 10000

int f[MAX_N + 5][MAX_N + 5] = {0};
int v[105], w[105];

int32_t main() {
    int V, n;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            if (j >= v[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
            else f[i][j] = f[i - 1][j];
        }
    }
    cout << f[n][V] << endl;
    return 0;
}
