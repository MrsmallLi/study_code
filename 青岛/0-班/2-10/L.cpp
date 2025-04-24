/*************************************************************************
	> File Name: L.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Feb 2025 10:38:51 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_N 200

string arr[MAX_N + 5];

bool CMP(const string &a, const string &b) {
    return a + b > b + a;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    string ans;
    sort(arr, arr + n, CMP);
    for (int i = 0; i < n; i++) {
        ans += arr[i];
    }
    cout << ans << endl;
    return 0;
}


