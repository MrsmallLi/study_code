/*************************************************************************
	> File Name: 3.1370D.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Apr 2025 07:33:52 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 200000
int a[MAX_N + 5];
int n, k, max_num = -1;

bool check(int x) {
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (cnt % 2 && a[i] <= x) {
            cnt += 1;
        } else if (cnt % 2 == 0) {
            cnt += 1;
        }
        if (cnt == k + 1) return true;
    }    
    cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (cnt % 2) {
            cnt += 1;
        } else if (cnt % 2 == 0 && a[i] <= x) {
            cnt += 1;
        }
        if (cnt == k + 1) return true;
    }
    return false;
}

int find() {
    int l = 1, r = max_num, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        max_num = max(max_num, a[i]);
    }
    cout << find() << endl;

    return 0;
}
