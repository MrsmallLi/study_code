/*************************************************************************
	> File Name: 3209.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Apr 2025 10:56:12 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int is_good_num(int x) {
    int i = 1;
    while (x) {
        int num = x % 10;
        if (num % 2 != i % 2) return 0;
        x /= 10;
        i += 1;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (is_good_num(i) == 0) continue;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}
