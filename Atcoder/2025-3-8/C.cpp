/*************************************************************************
	> File Name: C.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Mar 2025 08:20:15 PM CST
 ************************************************************************/

#include<iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 200000

int arr[MAX_N + 5];
int temp[MAX_N + 5];

bool CMP(int a, int b) {
    return a > b;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> temp[i];
    }
    sort(arr, arr + n, CMP);
    sort(temp, temp + m, CMP);
    long long ans = 0;
    long long num = 0;
    int cnt1 = 0, cnt2 = 0;
    while (cnt1 < n && arr[cnt1] >= 0) {
        num += arr[cnt1++];
    }
    while (cnt2 < m && cnt2 < cnt1 && temp[cnt2] > 0) {
        num += temp[cnt2++];
    }
    while (cnt1 < n && cnt2 < m && arr[cnt1] + temp[cnt2] >= 0) {
        num += arr[cnt1++] + temp[cnt2++];
    }
    ans = max(num, ans);
    cout << ans << endl;
    return 0;
}
