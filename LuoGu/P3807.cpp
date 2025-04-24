/*************************************************************************
	> File Name: 7038P.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Apr 2025 01:04:43 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000
#define int long long
int n, m, mod;

int f[MAX_N + 5];
int v[MAX_N + 5];

int quick_pow(int a, int b) {
    int ans = 1;
    int temp = a % mod;
    while (b) {
        if (b & 1) ans = (ans * temp) % mod;
        temp = (temp * temp) % mod;
        b >>= 1;
    }
    return ans;
}

void init() {
    f[0] = 1;
    v[0] = 1;
    for (int i = 1; i <= mod; i++) {
        f[i] = (i * f[i - 1]) % mod;
        v[i] = (quick_pow(f[i], mod - 2)) % mod;
    }
    return ;
}

int C(int n, int m) {
    if (n < m) return 0;
    return (f[n] * v[n - m] % mod) * v[m] % mod;
}

//C(n, m) = C(a_0, b_0)......C(a_k, b_k);
int Lucas(int n, int m) {
    if (!m) return 1;
    return Lucas(n / mod, m / mod) * C(n % mod, m % mod) % mod;
}


void solve() {
    cin >> n >> m >> mod;
    init();
    cout << Lucas(n + m, n) << endl;;
    return ;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();


    return 0;
}
