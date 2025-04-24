/*************************************************************************
	> File Name: 1.A.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 六  4/ 5 19:59:45 2025
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

int prime[1000005];	
vector<int> arr;

void init() {
    for (int i = 2; i * i <= 1000000; i++) {
        if (prime[i]) continue;
        for (int j = 2 * i; j <= 1000000; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= 1000000; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
    }
    const int maxn = 1e12;
    for (int i = 1; prime[i] <= 1000; i++) {
        for (int j = i + 1; j <= prime[0]; j++) {
            int bx = prime[i] * prime[i];
            int by = prime[j] * prime[j];
            for (int x = bx; x <= maxn / by; x *= bx) {
                for (int y = by; y <= maxn / x; y *= by) {
                    arr.push_back(x * y);
                }
            }
        }
    }
    sort(arr.begin(), arr.end());
    return ;
}

void solve() {
    int n;
    cin >> n;
    int l = 0, r = arr.size(), mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (arr[mid] <= n) l = mid + 1;
        else r = mid;
    }
    cout << arr[l - 1] << endl;
    return ;
}

int32_t main() {
    init();
    for (int i = 0; i < 10; i++) cout << arr[i] << endl;
    /*
    int tcase;
    cin >> tcase;
    while (tcase--) solve();
    */
    return 0;
}

