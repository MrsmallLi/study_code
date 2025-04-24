/*************************************************************************
	> File Name: 217.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 11:29:50 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int arr[MAX_N + 5];

bool CMP(int a, int b) {
    return a > b;
}


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1, CMP);
    int num;
    if (n & 1) {
        num = arr[n / 2 + 1];
    } else {
        num = arr[n / 2];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] < num) break;
        ans += 1;
    }
    cout << num << " " << ans << endl;
    return 0;
}
