/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Mar 2025 08:38:14 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define int __int128_t
int func(int x) {
    return x * x * x;
}

int find(int y, int num) {
    int l = 1, r = 1000000000;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        int z = func(mid + y) - func(mid);
        if (z > num) r = mid;
        else l = mid;
    }
    return l;
}

int32_t main() {
    long long n;
    cin >> n;
    int flag = 0;
    for (int i = 1; i <= 1e6 + 5; i++) {
        int y = find(i, n);
        if (func(i + y) - func(y) != n) continue;
        flag = 1;
        int32_t a = y;
        int32_t b = y + i;
        cout << b << " " << a << endl;
        break;
    }
    if (!flag) cout << -1 << endl;
    return 0;
}
