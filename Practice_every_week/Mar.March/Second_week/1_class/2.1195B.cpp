/*************************************************************************
	> File Name: 2.1195B.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Mar 2025 08:28:24 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define int long long

int f(int x) {
    return x * x + 3 * x;
}


int find(int n, int k) {
    int l = 0, r = n, mid;
    int num = 2 * n + 2 * k;
    while (l <= r) {
        mid = (l + r) / 2;
        if (f(mid) == num) return mid;
        else if (f(mid) < num) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return 0;
}



int32_t main() {
    int n, k;
    cin >> n >> k;
    cout << n - find(n, k) << endl;
    return 0;
}
