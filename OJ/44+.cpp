/*************************************************************************
	> File Name: 44+.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Apr 2025 02:28:00 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 1000000

int arr[MAX_N + 5];
int dp[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    arr[0] = INT_MIN;
    for (int i = 1; i <= n; i++)  {
        for (int j = 0; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl; 

    return 0;
}
