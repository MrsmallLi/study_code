/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Feb 2025 06:10:52 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


int main() {
    long long n;
    cin >> n;
    long long ans = 1;
    int i = 1;
    for (i = 1; i <= n; i++) {
        ans *= i;
        if (ans == n) break;
    }
    printf("%d\n", i);
    return 0;
}


