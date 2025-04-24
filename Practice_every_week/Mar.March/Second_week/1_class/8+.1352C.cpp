/*************************************************************************
	> File Name: 8+.1352C.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Mar 2025 08:01:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define int long long

int find(int n, int k) {
    int l = 0, r = k, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (k >= mid * (n - 1)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int x = find(n, k);
    if (k % (n - 1) == 0) {
        cout << x * n - 1 << endl;
    } else {
        cout << x * n + (k % (n - 1)) << endl;
    }
    return ;
}


int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
