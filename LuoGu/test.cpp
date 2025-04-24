/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Apr 2025 01:32:01 AM CST
 
 ************************************************************************/

 #include <iostream>

using ll = long long;

static constexpr int MAXN = 100010;

ll bc[MAXN+1];


ll qpow(ll x, ll y, ll p) {

    ll tmp = x % p;
    ll ans = 1;
    while(y) {
        if (y & 1) ans = ans * tmp % p;
        tmp = tmp * tmp % p;
        y >>= 1;
    }

    return ans;
}
ll C(ll n, ll m, ll p) {
    if (n < m) return 0;
    return  (bc[n] * qpow(bc[m], p - 2, p ) % p * qpow(bc[n - m], p - 2, p) % p);
}
ll  Lucas(ll n, ll m, ll p) {
   if (!m) return 1;
    return  Lucas( n / p, m / p, p) * C(n % p, m % p, p) % p;
}
int main( int argc, char *argv[])
{
    ll n;
    ll m;
    ll p;
    int t;
    std::cin >> t;



    while (t--) {

        std::cin >> n >> m >> p;

        bc[0] = 1;
        for (int i = 1; i <= p;i++) {
            bc[i] =  bc[i - 1] * i % p;
        }

        ll ans = Lucas(n + m, m, p);
        std::cout << ans << std::endl;
    }


    return 0;
}
