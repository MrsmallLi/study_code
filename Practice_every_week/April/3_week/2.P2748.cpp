/*************************************************************************
	> File Name: 2.P2748.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Apr 2025 07:19:14 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

#define int long long

int32_t main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    priority_queue<int> more, less;
    int ans = 0;
    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;
        //a - b > 0, 泥土多了
        for (int k = 1; k <= a - b; k++) {
            if (less.empty() || z * i - less.top() > y) {
                ans += y;
                more.push(z * i + y);
            } else {
                ans += z * i - less.top();
                more.push(z * i + z * i - less.top());
                less.pop();
            }
        }
        //b - a > 0, 泥土少的情况
        for (int k = 1; k <= b - a; k++) {
            if (more.empty() || z * i - more.top() > x) {
                ans += x;
                less.push(z * i + x);
            } else {
                ans += z * i - more.top();
                less.push(z * i + z * i - more.top());
                more.pop();
            }
        }
    }
    cout << ans << endl;

    return 0;
}
