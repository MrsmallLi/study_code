/*************************************************************************
	> File Name: 231A.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 03:29:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c < 2) continue;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}
