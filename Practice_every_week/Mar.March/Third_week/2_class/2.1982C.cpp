/*************************************************************************
	> File Name: 2.1982C.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Mar 2025 06:40:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define int long long
#define MAX_N 100000

int arr[MAX_N + 5];

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int i = 0, j = 0;
    int sum = 0;
    int ans = 0;
    while (i < n && j < n) {
        while (j < n && sum < l) sum += arr[j++];
        while (i < n && sum > r) sum -= arr[i++];
        if (sum >= l && sum <= r) {
            //printf("%lld, %lld, %lld\n", i, j, sum);
            ans += 1; 
            i = j;
            sum = 0;
        }
    }
    cout << ans << endl;
    return ;
}


int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
