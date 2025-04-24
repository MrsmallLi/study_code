/*************************************************************************
	> File Name: 7.1486.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Apr 2025 05:25:40 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 200000

int n, k, mid_num, max_num;
int a[MAX_N + 5];
int arr[MAX_N + 5];

bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        arr[i] = arr[i - 1] + (a[i] >= mid ? 1 : -1);
    }
    int ans = 0, min_num = 0;
    for (int i = k; i <= n; i++) {
        min_num = min(min_num, arr[i - k]);
        ans = max(ans, arr[i] - min_num);
        if (ans > 0) return true;
    }
    return ans > 0;
}

int find() {
    int l = 0, r = max_num, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid; 
        } else {
            r = mid - 1;
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
