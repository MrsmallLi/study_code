/*************************************************************************
	> File Name: 6.1613C.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Mar 2025 11:26:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100
#define int long long

int arr[MAX_N + 5];

bool check(int x, int n, int h) {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += min(x, arr[i + 1] - arr[i]);
    }
    sum += x;
    return sum >= h;
}

int find(int n, int h) {
    int l = 1, r = h, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid, n, h)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

void solve() {
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << find(n, h) << endl;
    return ;
}


int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
