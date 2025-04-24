/*************************************************************************
	> File Name: 1474B.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Mar 2025 05:20:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define int long long

#define MAX_N 200000

int prime[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int find(int x) {
    int l = 1, r = prime[0], mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (prime[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1; 
        }
    }
    return prime[l];
}

void solve() {
    int d;
    cin >> d;
    int a = find(1 + d);
    int b = find(a + d);
    cout << a * b << endl;
    return ;
}

int32_t main() {
    int t;
    cin >> t;
    init();
    while (t--) solve();
    return 0;
}
