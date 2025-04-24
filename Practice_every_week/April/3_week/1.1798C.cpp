/*************************************************************************
	> File Name: 1.1798C.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Apr 2025 10:32:13 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 200000
#define int long long
int a[MAX_N + 5], b[MAX_N + 5];

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int cost = b[0], lcm_num = a[0] * b[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        lcm_num = gcd(lcm_num, a[i] * b[i]);
        cost = lcm(cost, b[i]);
        if (lcm_num % cost == 0) continue;
        ans += 1;
        lcm_num = a[i] * b[i];
        cost = b[i];
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
