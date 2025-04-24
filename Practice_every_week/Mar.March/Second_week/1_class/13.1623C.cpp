/*************************************************************************
	> File Name: 13.1623C.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Mar 2025 03:24:07 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 200000
#define int long long

int arr[MAX_N + 5];
int num[MAX_N + 5];

bool check(int x, int n) {
    for (int i = 1; i <= n; i++) num[i] = arr[i];
    for (int i = n; i >= 3; i--) {
        if (num[i] >= x) {
            int move = min(arr[i] / 3, (num[i] - x) / 3);
            num[i - 1] += move;
            num[i - 2] += move * 2;
        }
        else {
            return false;
        }
    }
    if (num[1] < x || num[2] < x) return false;
    return true;
}

int find(int r, int n) {
    int l = 0, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid, n)) {
            l = mid; 
        } else {
            r = mid - 1;
        }
    }
    return l;
}


void solve() {
    int n;
    cin >> n;
    int r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        r = max(arr[i], r);
    }
    cout << find(r, n) << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
