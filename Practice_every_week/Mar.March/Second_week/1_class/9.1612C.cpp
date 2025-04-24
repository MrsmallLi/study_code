/*************************************************************************
	> File Name: 9.1612C.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Mar 2025 08:21:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define int long long


int func(int mid, int k) {
    if (mid <= k) {
        return ((mid + 1) * mid / 2);
    } else {
        int sum = (k + 1) * k / 2;
        int m = mid - k;
        sum += (k - 1 + k - m) * m / 2;
        return sum;
    }
}

int find(int k, int x) {
    int l = 1, r = 2 * k - 1, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if ((func(mid, k) <= x)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}



void solve() {
    int k, x;
    cin >> k >> x;
    int ans = find(k, x);
    if (x > func(ans, k) && ans < 2 * k - 1)  {
        cout << ans + 1 << endl;
    }
    else cout << ans << endl;
    return ;
}


int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
