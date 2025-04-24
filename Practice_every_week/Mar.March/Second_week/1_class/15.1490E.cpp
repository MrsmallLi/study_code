/*************************************************************************
	> File Name: 15.1490E.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Mar 2025 06:59:09 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
#define MAX_N 200000

class A {
public :
    int x, ind;
};

A a[MAX_N + 5];
int b[MAX_N + 5];

bool CMP(const A &a, const A &b) {
    return a.x < b.x;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)  {
        cin >> a[i].x;
        a[i].ind = i;
    }
    sort(a + 1, a + n + 1, CMP);
    for (int i = 1; i <= n; i++) {
        b[i] = a[i].x + b[i - 1];
    }
    int dp[MAX_N + 5] = {0};
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (b[i] < a[i + 1].x) continue;
        dp[i] ^= dp[i + 1];
    }
    int l = 1, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (dp[mid]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    vector<int> temp;
    for (int i = l; i <= n; i++) {
        temp.push_back(a[i].ind);
    }
    sort(temp.begin(), temp.end());
    cout << temp.size() << endl;
    for (int i = 0; i < temp.size(); i++) {
        i && printf(" ");
        cout << temp[i];
    }
    cout << endl;
    return ;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
