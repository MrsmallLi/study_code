/*************************************************************************
	> File Name: 1.1223C.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 06 Apr 2025 08:47:43 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define MAX_N 200000
#define int long long

int p[MAX_N + 5];
int n, x, a, y, b, k;

bool check(int mid) {
    priority_queue<int> pq;
    for (int i = 1; i <= mid; i++) {
        if (i % a == 0 && i % b == 0) {
            pq.push(x + y);
        } else if (i % a == 0) {
            pq.push(x);
        } else if (i % b == 0) {
            pq.push(y);
        }
    }
    int temp = 0;
    int i = 1;
    while (!pq.empty()) {
        temp += pq.top() * p[i++];
        pq.pop();
    }
    //printf("temp = %lld\n", temp);
    return temp >= k;
}


int find() {
    int l = 1, r = n + 1, mid = 0;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] /= 100;
    }
    cin >> x >> a;
    cin >> y >> b;
    cin >> k;
    sort(p + 1, p + n + 1, greater<int>());
    int ans = find();
    if (ans == n + 1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return ;
}

int32_t main() {
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}
