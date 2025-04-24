/*************************************************************************
	> File Name: C.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Feb 2025 09:49:29 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

#define MAX_N 200000




int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[MAX_N + 5] = {0};
        int s[MAX_N + 5] = {0};
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s[i] += s[i - 1] + arr[i];
        }
        sort(arr, arr + n);
        int l = 0, r = n - 1;
        long long ans = 0;
        while (l <= r) {
            int x = 0;
            while (l <= r && x < arr[r] && x + arr[l] <= arr[r]) {
                x += arr[l];
                ans += arr[l];
                l += 1;
            }
        }
    }
    return 0;
}
