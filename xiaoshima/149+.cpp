/*************************************************************************
	> File Name: 149+.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Nov 2024 03:43:44 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int is_prime(int x) {
    if (x == 0 || x == 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;

}

int main() {
    int l, r;
    cin >> l >> r;
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (is_prime(i)) cnt++;
    }
    cout << cnt << endl;;
    
    return 0;
}

