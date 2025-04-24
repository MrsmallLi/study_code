/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Mar 2025 08:26:39 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;


#define int long long

#define MAX_N 300000
int a[MAX_N + 5];
int b[MAX_N + 5];
int c[MAX_N + 5];
unordered_map<int, int> mp1;
unordered_map<int, int> mp2;

int32_t main() {
    int n;
    cin >> n;
    b[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mp1[a[0]] = 1;
    for (int i = 1; i < n; i++) {
        b[i] = b[i - 1];
        if (mp1[a[i]]) continue;
        mp1[a[i]] = 1;
        b[i] += 1;
    }
    c[n - 1] = 1;
    mp2[a[n - 1]] = 1;
    for (int i = n - 2; i >= 0; i--) {
        c[i] = c[i + 1];
        if (mp2[a[i]]) continue;
        mp2[a[i]] = 1;
        c[i] += 1;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, b[i] + c[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
