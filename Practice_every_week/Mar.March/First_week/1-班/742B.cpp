/*************************************************************************
	> File Name: 742B.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 10:01:44 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 200000
#define int long long

int arr[MAX_N + 5];
int flag[MAX_N + 5];


int32_t main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int num = arr[i] ^ x;
        ans = ans + flag[num];
        flag[arr[i]] += 1;
    }
    cout << ans << endl;
    return 0;
}
