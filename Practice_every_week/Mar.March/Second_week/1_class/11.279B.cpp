/*************************************************************************
	> File Name: 11.279B.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Mar 2025 12:52:50 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000
int arr[MAX_N + 5];

bool check(int x, int n, int t) {
    int head = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (i - head + 1 < x) continue;
        if (sum <= t) return true;
        sum -= arr[head++];
    }
    return false;
}

int find(int n, int t) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid, n, t)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}


int main() {
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << find(n, t) << endl;
    return 0;
}
