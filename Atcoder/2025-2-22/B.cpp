/*************************************************************************
	> File Name: B.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 Feb 2025 08:36:07 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_N 500

string arr[MAX_N + 5];

int CMP(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length();
    for (int i = 0; a[i]; i++) {
        if (a[i] == b[i]) continue;
        return a[i] < b[i];
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, CMP);
    string ans;
    for (int i = 0; i < n; i++) ans += arr[i];
    cout << ans << endl;
    return 0;
}
