/*************************************************************************
	> File Name: 239.c
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 05:16:05 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define p(a) ((a) * (a))
typedef long long ll;

void f(ll n, ll s, ll *x, ll *y) {
    if (n == 1) {
        if (s == 1) *x = 0, *y = 0;
        else if (s == 2) *x = 0, *y = 1;
        else if (s == 3) *x = 1, *y = 1;
        else if (s == 4) *x = 1, *y = 0;
        return ;
    }
    long long L = 1LL << (n - 1);
    long long block = L * L;
    long long xx, yy;
    if (s <= block) {
        f(n - 1, s, &xx, &yy);
        *x = yy, *y = xx;
    }
    else if (s <= 2 * block)  {
        f(n - 1, s - block, &xx, &yy);
        *x = xx, *y = yy + L;
    }
    else if (s <= 3 * block) {
        f(n - 1, s - 2 * block, &xx, &yy);
        *x = xx + L, *y = yy + L;
    }
    else  {
        f(n - 1, s - 3 * block, &xx, &yy);
        *x = 2 * L - 1 - yy;
        *y = L - 1 - xx;
    }
    return ;
}

int main() {
    ll t, n, s, d;
    scanf("%lld", &t);
    for (int i = 0; i < t; i++) {
        scanf("%lld%lld%lld", &n, &s, &d);
        ll sx, sy, dx, dy;
        f(n, s, &sx, &sy);
        f(n, d, &dx, &dy);
        printf("%.0lf\n", 10 * sqrt(p(dx - sx) + p(dy - sy)));
    }
    return 0;
}
