/*************************************************************************
	> File Name: 8.1352C.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Mar 2025 07:23:53 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int x = k / (n - 1) * n - 1;
    int y = k % (n - 1);
    if (y) y += 1;
    cout << x + y << endl;
    return ;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
