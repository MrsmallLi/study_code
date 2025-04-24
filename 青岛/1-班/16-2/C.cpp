/*************************************************************************
	> File Name: C.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 07:52:16 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

#define MAX_N 200000
#define int long long

int a[MAX_N + 5];
int b[MAX_N + 5];


int32_t main() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a + n, greater());
    sort(b, b + n, greater());
    int a_all = 0, b_all = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        a_all += a[i];
        b_all += b[i];
        ans += 1;
        if (a_all > x || b_all > y) break;
    }
    cout << ans << endl;
    return 0;
}
