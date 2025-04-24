/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Apr 2025 08:09:43 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <map>
using namespace std;

#define int long long
map<int, int> mp;
int n;

int check(int x) {
    int num = n / x;
    int l = 1, r = n, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        //printf("cnt = %d, mid = %d\n", cnt, mid);
        if (mid <= num / mid) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int32_t main() {
    cin >> n;
    int ans = 0;
    for (int i = 1; ; i++) {
        int num = 1LL << i;
        if (num > n) break;
        int x = check(num);
        ans += (x + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
