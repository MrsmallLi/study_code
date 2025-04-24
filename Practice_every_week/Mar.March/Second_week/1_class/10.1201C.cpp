/*************************************************************************
	> File Name: 10.1201C.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Mar 2025 12:26:47 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

#define MAX_N 200000
#define int long long

int arr[MAX_N + 5];

bool check(int x, int n, int k) {
    int cnt = 0;
    for (int i = n / 2; i < n; i++) {
        if (arr[i] >= x) break;
        cnt += x - arr[i];
        if (cnt > k) return false;
    }
    return cnt;
}

int find(int n, int k) {
    int l = arr[n / 2], r = arr[n / 2] + k, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid, n, k)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int32_t main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);
    int ind = arr[n / 2];
    int ans = find(n, k);
    cout << ans << endl;
    return 0;
}
