/*************************************************************************
	> File Name: D.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 09:52:57 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

vector<int> x;

int32_t main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] != '1') continue;
        x.push_back(i);
    }
    for (int i = 0; i < x.size(); i++) {
        x[i] = x[i] - i;
    }
    int x1 = x[x.size() / 2];
    int ans = 0;
    for (int i = 0; i < x.size(); i++) {
        ans += abs(x[i] - x1);
    }
    cout << ans << endl;
    return 0;
}
