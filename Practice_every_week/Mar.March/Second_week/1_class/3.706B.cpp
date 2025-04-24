/*************************************************************************
	> File Name: 3.706B.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Mar 2025 09:08:42 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000000
int n;

int arr[MAX_N + 5];

int find(int d) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (d >= arr[mid]) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

void solve() {
    int d;
    cin >> d;
    int ans = find(d);
    cout << ans << endl;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
