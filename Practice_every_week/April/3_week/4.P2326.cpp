/*************************************************************************
	> File Name: 4.P2326.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Apr 2025 09:15:24 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100000
#define int long long
int a[MAX_N + 5];
int b[MAX_N + 5];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b[n + 1] = {0};
    long long ans = 0;
    for (int k = 20; k >= 0; k--) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((a[i] & (1 << k)) == 0) continue;
            b[cnt++] = a[i];
        }
        if (cnt >= 2) {
            for (int i = 0; i < cnt; i++) a[i] = b[i];
            n = cnt;
        }
    }
    cout << (a[0] & a[1]) << endl;
    return ;
}

int32_t main() {
    int t;
    cin >> t;
    int i = 1;
    while (t--) {
        cout << "Case #" << i << ": ";
        i++;
        solve();
    }
    return 0;
}
