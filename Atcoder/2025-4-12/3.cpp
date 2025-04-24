/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 12 Apr 2025 08:14:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 2000000

#define int long long

int a[MAX_N + 5];
long long mod = 1000000000;

int32_t main() {
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    for (int i = 0; i <= n; i++) {
        if (i < k) {
            a[i] = 1;
            sum = (sum + a[i]) % mod;
        } else {
            a[i] = sum % mod;
            sum = (sum - a[i - k] + a[i] + mod) % mod;
        }
    }
    cout << a[n] << endl;
    return 0;
}
