/*************************************************************************
	> File Name: 12.1436C.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Mar 2025 10:59:56 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1010
#define int long long
int n, x, pos;
int less_num, big_num;
long long MOD = 1e9 + 7;

int f[MAX_N + 5];
int v[MAX_N + 5];

int quick_pow(int a, int b) {
    int temp = 1;
    while (b) {
        if (b & 1) temp = (temp * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return temp;
}


void init() {
    f[0] = 1;
    v[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        f[i] = (f[i - 1] * i) % MOD;
        v[i] = quick_pow(f[i], MOD - 2);
    }
    return ;
}

void find(int n, int x, int pos) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (mid > pos) {
            big_num++;
            r = mid;
        } else if (mid < pos){
            less_num++;
            l = mid + 1;
        } else {
            l = mid + 1;
        }
    }
    return ;
}
int C(int n, int m) {
    if (m > n || m < 0) return 0;
    return ((f[n] * v[n - m]) % MOD) * v[m] % MOD;
}

int A(int n, int m) {
    cout << n << n - m << endl;
    return (f[n] * v[n - m]) % MOD;
}

int32_t main() {
    cin >> n >> x >> pos;
    init();
    find(n, x, pos);
    int other = n - less_num - big_num - 1;
    printf("less = %lld, more = %lld\n", less_num, big_num);
    printf("less_x = %lld, more_x = %lld\n", x - 1, n - x);
    //printf("%lld %lld %lld\n", C(n - x, big_num), C(x - 1, less_num), f[other]);
    //int ans = ((C(n - x, big_num) * f[big_num]) % MOD * (C(x - 1, less_num) * f[less_num]) % MOD) % MOD * f[other] % MOD;
    int ans = A(n - x, big_num) * A(x - 1, less_num) % MOD * f[other] % MOD;
    cout << ans << endl;
    return 0;
}
