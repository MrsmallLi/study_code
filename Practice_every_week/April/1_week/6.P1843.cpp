/*************************************************************************
	> File Name: 6.P1843.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Apr 2025 05:01:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 500000
int n, a, b;
int w[MAX_N + 5];

bool check(int mid) {
    int cnt = mid;
    for (int i = 0; i < n; i++) {
        if (mid * a >= w[i]) continue;
        cnt -= (w[i] - mid * a + b - 1) / b;
    }
    return cnt >= 0;
}

int find() {
    int l = 0, r = 1e5, mid;
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

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    cout << find() << endl;
    return 0;
}
