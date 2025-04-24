/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 08:20:00 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

#define MAX_N 200000
vector<vector<int>> num(MAX_N + 5, vector<int>(0));

int main() {
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        int a, b;  
        cin >> a >> b;
        int flag = 1;
        for (int i = 0; i < num[a].size(); i++) {
            if (num[a][i] != b) continue;
            flag = 0;
            break;
        }
        for (int i = 0; flag && i < num[b].size(); i++) {
            if (num[b][i] != a) continue;
            flag = 0;
            break;
        }
        if (!flag || a == b) {
            ans += 1;
        } else {
            num[a].push_back(b);
            num[b].push_back(a);
        }
    }
    cout << ans << endl;
    return 0;


}
