/*************************************************************************
	> File Name: C.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Mar 2025 08:26:44 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

#define MAX_N 200000

int arr[MAX_N + 5];
unordered_map<int, int> mp;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (mp.find(arr[i]) == mp.end()) {
            mp[arr[i]] = i;
        } else {
            ans = min(ans, i - mp[arr[i]] + 1);
        }
    }
    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
