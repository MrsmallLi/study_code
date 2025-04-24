/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Apr 2025 08:03:49 PM CST
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;

#define int long long
int max_num = 1e9;

int32_t main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        long long num = pow(n, i);
        if (num > max_num || ans + num > max_num) {
            ans = -1;
            break;
        }
        ans += num;
    }
    if (ans == -1) {
        cout << "inf" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
