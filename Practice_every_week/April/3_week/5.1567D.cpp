/*************************************************************************
	> File Name: 5.1567D.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Apr 2025 01:16:43 PM CST
 ************************************************************************/

/*************************************************************************
	> File Name: 107.CF1567D.cpp
	> Author:
	> Mail:
	> Created Time: 一  4/21 20:23:15 2025
 ************************************************************************/


#include <iostream>
using namespace std;

#define int long long

void solve() {
    int n, s;
    cin >> s >> n;
    for (int i = n - 1; i >= 1; i--) {
        int temp = 1;
        while (s - temp >= i) temp *= 10;
        temp /= 10;
        cout << temp << " ";
        s -= temp; 
    }
    cout << s << endl;
    return ;
}


int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
