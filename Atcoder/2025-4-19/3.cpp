/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Apr 2025 08:14:39 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<int, set<int>> mp1;
map<int, set<int>> mp2;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        int a;
        while (k--) {
            cin >> a;
            mp1[a].insert(i);
            mp2[i].insert(a);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (auto x : mp1[k]) {
            mp2[x].erase(k);
            if (mp2[x].size() != 0) continue;
            cnt += 1;
        }
        cout << cnt << endl;
    }




    return 0;
}
