/*************************************************************************
	> File Name: 838.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Apr 2024 09:39:24 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <queue>
#include <cinttypes>
#include <climits>
#include <cmath>
using namespace std;

int min_num(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    return a;
}

int func(queue<int> que1, queue<int> que2, queue<int> que3) {
    int ans = INT_MAX;
    while (!que1.empty() && !que2.empty() && !que3.empty()) {
        int a = que1.front();
        int b = que2.front();
        int c = que3.front();
        int d = min_num(a, b, c);
        ans = min(ans, (int)(fabs(a - b) + fabs(a - c) + fabs(b - c)));
        if (d == que1.front()) {
            que1.pop();
            if (que1.empty()) break;
        } else if (d == que2.front()) {
            que2.pop();
            if (que2.empty()) break;
        } else {
            que3.pop();
            if (que2.empty()) break;
        }
    }
    return ans;
}

int main() {
    int m, n, k, x;
    queue<int> que1, que2, que3;
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++) {
        cin >> x;
        que1.push(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        que2.push(x);
    }
    for (int i = 0; i < k; i++) {
        cin >> x;
        que3.push(x);
    }
    cout << func(que1, que2, que3) << endl;
    return 0;
}
