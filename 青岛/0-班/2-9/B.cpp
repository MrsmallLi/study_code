/*************************************************************************
	> File Name: B.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Feb 2025 09:21:08 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX_N 200000
#define int long long

int num[MAX_N + 5];
unordered_map<int, int> mp;


int32_t main() {
    int n;
    cin >> n;
    for (int i = 0, a, b, flag = 0; i < n; i++) {
        cin >> a;
        if (mp.find(a) == mp.end()) b = -1;
        else b = mp[a];
        mp[a] = i + 1;
        if (flag) cout << " ";
        cout << b;
        flag = 1;
    }
    cout << endl;
    return 0;
}
