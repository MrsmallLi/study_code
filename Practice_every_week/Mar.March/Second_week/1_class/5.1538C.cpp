/*************************************************************************
	> File Name: 5.1538C.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Mar 2025 01:42:25 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 200000
#define int long long 

int arr[MAX_N + 5];

int low_find(int l, int r, int x) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int up_find(int l, int r, int x) {
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (arr[mid] <= x) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}



void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        cin >> arr[i] ;
    }
    sort(arr, arr + n);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] + arr[n - 1] < l) continue;
        if (arr[i] + arr[i + 1] > r) continue;
        int left = low_find(i + 1, n - 1, l - arr[i]);
        int right = up_find(i + 1, n - 1, r - arr[i]);
        ans += right - left + 1;
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
