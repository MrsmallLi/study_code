/*************************************************************************
	> File Name: D.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Feb 2025 10:12:04 AM CST
 ************************************************************************/

#include<iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX_N 5000

long long binary_serch(int x, int *b, int n) {
    int l = 0, r = n - 1; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[MAX_N + 5] = {0};
        int b[MAX_N + 5] = {0};
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        sort(a, a + n);
        sort(b, b + n);
        long long ans = INT_MAX;
        for (int i = 0; i < n; i++) {
        }
        cout << ans << endl;
    }
    return 0;
}
