/*************************************************************************
	> File Name: 217.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 01:12:54 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;


#define MAX_N 100000

int arr[MAX_N + 5];

bool CMP(int a, int b) { return a > b; }

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1, CMP);
    int s;
    if (n & 1) {
        s = n / 2 + 1;
    } else {
        s = n / 2;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] < arr[s]) break;
        ans += 1;
    }
    cout << arr[s] << " " << ans << endl;
    return 0;
}
