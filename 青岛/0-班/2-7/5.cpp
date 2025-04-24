/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Feb 2025 07:38:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;



int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i * j == n) continue;
            ans += i * j;
        }
    }
    cout << ans << endl;
}
