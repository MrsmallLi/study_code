/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Feb 2025 07:31:09 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

int arr[500005];

long long find(int x, int n) {
    int l = -1, r = n - 1, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (arr[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long ind = find(arr[i] / 2, n);
        if (ind < 0) continue;
        ans += ind + 1;
    }
    cout << ans << endl;
    return 0;
}
