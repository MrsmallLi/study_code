/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Jan 2025 09:20:40 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<long long> p;
long long n, m;
typedef long long ll;

bool check(long long x, ll *cnt, ll *cost) {
    long long now_cost = 0, now_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] > x) continue;
        ll c = (x / p[i] + 1) / 2;
        if (m < p[i] * c * c) return false;
        now_cost += c * c * p[i];
        if (now_cost > m) return false;
        now_cnt += c;
    }
    *cnt = now_cnt;
    *cost = now_cost;
    return true;
}

long long select() {
    long long l = 0, r = m + 1, mid, mx_cost = 0, mx_cnt = 0;
    while (l < r) {
        mid = (l + r + 1) / 2;
        long long cnt = 0, cost = 0;
        if (check(mid, &cnt, &cost)) {
            l = mid;
            mx_cost = max(mx_cost, cost);
            mx_cnt = max(mx_cnt, cnt);
        }
        else {
            r = mid - 1;
        }
    }
    m -= mx_cost;
    mx_cnt += m / (l + 1);
    return mx_cnt;
}





int main() {
    //读入
    cin >> n >> m;
    for (long long i = 0, a; i < n; i++) {
        cin >> a;
        p.push_back(a);
    }
    cout << select() << endl;
    return 0;
}

