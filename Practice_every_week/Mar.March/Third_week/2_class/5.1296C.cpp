/*************************************************************************
	> File Name: 5.1296C.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Mar 2025 07:42:25 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>
using namespace std;

void solve() {
    int n;
    string str;
    cin >> n >> str;
    int l = -1, r = n;
    int x = 0, y = 0;
    map<pair<int, int>, int> mp;
    mp[ {0, 0} ] = 0;
    for (int i = 0; str[i]; i++) {
        switch (str[i]) {
            case 'L' : {
                x -= 1; 
            } break;
            case 'R' : {
                x += 1; 
            } break;
            case 'U' : {
                y += 1; 
            } break;
            case 'D' : {
                y -= 1; 
            } break;
        }
        pair<int, int> a(x, y);
        if (mp.count(a) && (r - l + 1) > (i - mp[a] + 1)) {
            l = mp[a];
            r = i;
        }
        mp[a] = i + 1;
    }
    if (l < 0) {
        cout << -1 << endl;
    } else {
        cout << l + 1 << " " << r + 1 << endl;
    }
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
