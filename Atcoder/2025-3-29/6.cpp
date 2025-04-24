/*************************************************************************
	> File Name: 6.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Mar 2025 08:49:48 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define int long long

#define MAX_N 200000

int mod = 998244353;
int num[MAX_N + 5];
int y[15][MAX_N + 5];
int f[20];
int v[20];

int quick(int a, int b) {
    int temp = 1;
    while (b) {
        if (b & 1) {
            temp = (a * temp) % mod;
        }
        b >>= 1;
        a = (a * a) % mod;
    }
    return temp;
}

void init() {
    f[0] = 1;
    v[0] = 1;
    for (int i = 1; i <= 10; i++) {
        f[i] = i * f[i - 1] % mod;
        v[i] = quick(f[i], mod - 2) % mod;
    }
    return ;
}

int C(int n, int m) {
    //return f[n] * v[m] % mod * v[n - m] % mod;
    return f[n]  / (f[n - m] * f[m]) % mod;
}

int32_t main() {
    int n, k;
    cin >> n >> k;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        num[i] = (num[i] + num[i - 1]) % mod;
    }
    y[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int temp = 1;
        for (int p = 0; p <= k; p++) {
            y[p][i] = (temp + y[p][i - 1]) % mod;
            temp = (temp * num[i]) % mod;
        }
    }
    int ans = 0;
    //int b = (-1 % mod);
    //cout << b << endl;
    for (int i = 1; i <= n; i++) {
        for (int p = 0; p <= k; p++) {
            int sign = (p % 2 == 0) ? 1 : mod - 1;
            int s = sign * C(k, p) % mod * quick(num[i], k - p) % mod * y[p][i - 1] % mod;
            //int s = quick(num[i], k - p) % mod * y[p][i - 1] % mod;
            ans = (ans + s) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}
