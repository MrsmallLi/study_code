/*************************************************************************
	> File Name: 3.2067B.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Mar 2025 06:52:33 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp1[a] += 1;
    }
    for (auto x : mp1) {
        int a = x.first;
        int b = x.second;
        if (x.second == 1) {
            cout << "No" << endl;
            return ;
        }
        mp1[x.first + 1] += x.second - 2;
    }
    cout << "Yes" << endl;
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
