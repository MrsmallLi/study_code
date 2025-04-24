/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Apr 2025 08:39:05 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;


class A {
public :
    double s, c, p;
};

int n, x;
A arr[15];
double dp[500000];
double val[500000];

double quick(double p, int k) {
    double ans = 1;
    p = p * 1.0 / 100;
    while (k) {
        if (k & 1) ans = ans * p;
        p *= p;
        k >>= 1;
    }
    return ans;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int s, c, p;
        cin >> s >> c >> p;
        int num = x / c;
        for (int k = 1; num > 0; num -= k, k *= 2){
            for (int j = x; j >= k * c; j--) {
                if (val[j] == 0) val[j] = 1;
                if (dp[j] < dp[i - k * c] + val[j] * quick(p * 1.0, k) * s * 1.0) {
                    dp[j] = dp[i - k * c] + val[j] * quick(p * 1.0, k) * s * 1.0;
                    val[j] = val[j] * quick(p * 1.0, k);
                } 
                if (dp[j] < dp[i - k * c] + val[j] * quick((100 - p) * 1.0, k) * dp[i - k * c] * 1.0) {
                    dp[j] = dp[i - k * c] + val[j] * quick((100 - p) * 1.0, k) * 1.0 * dp[i - k * c];
                    val[j] = val[j] * quick((100 - p) * 1.0, k);
                }
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}
