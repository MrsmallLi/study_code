/*************************************************************************
	> File Name: P1226.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 09:07:41 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long quick_mul(long long a, long long b, long long p) {
    long long ans = 0, temp = a;
    while (b) {
        if (b & 1) ans = (ans + temp) % p;
        temp = (temp + temp) % p;
        b >>= 1;
    }
    return ans;
}


long long quick_pow(long long a, long long b, long long p) {
    long long ans = 1, temp = a;
    while (b) {
        if (b & 1) ans = quick_mul(ans, temp, p);
        temp = quick_mul(temp, temp, p);
        b >>= 1;
    }
    return ans;
}


int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    printf("%lld^%lld mod %lld=%lld\n", a, b, p, quick_pow(a, b, p));
    return 0;
}
