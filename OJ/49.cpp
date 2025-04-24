/*************************************************************************
	> File Name: 49.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Apr 2025 02:17:08 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000

int dp[MAX_N + 5];

int main() {
    int V, n;
    cin >> V >> n;
    for (int i = 1, w, v, s; i <= n; i++) {
        cin >> w >> v >> s;
        for (int k = 1; s > 0; s -= k, k *= 2) {
            k = min(s, k);
            for (int j = V; j >= k * w; j--) {
                dp[j] = max(dp[j], dp[j - k * w] + k * v);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
