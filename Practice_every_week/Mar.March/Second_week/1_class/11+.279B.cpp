/*************************************************************************
	> File Name: 11+.279B.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Mar 2025 01:00:04 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000
#define int long long

int arr[MAX_N + 5];

int32_t main() {
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum = 0, head = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum <= t) {
            ans = max(ans, i - head + 1);
            continue;
        }
        while (head <= i && sum > t) sum -= arr[head++];
    }
    cout << ans << endl;
    return 0;
}
