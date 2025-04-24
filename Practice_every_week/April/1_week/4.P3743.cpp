/*************************************************************************
	> File Name: 4.P3743.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Apr 2025 06:03:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000
double MIN_NUM = 0.000001;
int n, p;
double a[MAX_N + 5], b[MAX_N + 5];
long long all_spend;

bool check(double mid) {
    double charge = p * mid;
    double spend = 0;
    for (int i = 0; i < n; i++) {
        if (mid * a[i] <= b[i]) continue;
        spend += mid * a[i] - b[i];
    }
    return charge >= spend;
}

double solve() {
    if (all_spend <= p) return -1;
    double l = 0, r = 1e10, mid;
    while (l + MIN_NUM < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int32_t main() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        all_spend += a[i];
    }
    cout << solve() << endl;
    return 0;
}
