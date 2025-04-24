/*************************************************************************
	> File Name: 1.1859B.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Mar 2025 04:26:04 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
#define MAX_N 25000



void solve() {
    int n;
    cin >> n;
    int all_min_num = INT_MAX;
    int all_next_min_num = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        int min_num = INT_MAX;
        int next_min_num = INT_MAX;
        for (int j = 0, num; j < m; j++) {
            cin >> num;
            if (min_num > num) {
                next_min_num = min_num;
                min_num = num;
            } else {
                next_min_num = min(next_min_num, num);
            }
        }
        all_min_num = min(min_num, all_min_num);
        all_next_min_num = min(next_min_num, all_next_min_num);
        sum += next_min_num;
    }
    sum -= all_next_min_num;
    sum += all_min_num;
    cout << sum << endl;
    return ;
}


int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
