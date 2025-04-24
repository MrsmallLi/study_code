/*************************************************************************
	> File Name: 3.1705D.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Apr 2025 07:19:51 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define int long long
#define MAX_N 200000

void solve() {
    int n;
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;
    if (s[0] != t[0] || s[n - 1] != t[n - 1]) {
        cout << -1 << endl;
        return ;
    }
    vector<int> a, b;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] ^ s[i + 1]) a.push_back(i);
        if (t[i] ^ t[i + 1]) b.push_back(i);
    }
    if (a.size() != b.size()) {
        cout << -1 << endl;
        return ;
    }
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans += abs(a[i] - b[i]);
    }
    cout << ans << endl;
    return ;
}

int32_t main() {
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}
