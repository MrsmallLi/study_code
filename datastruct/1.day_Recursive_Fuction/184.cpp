/*************************************************************************
	> File Name: 184.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 04:18:24 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int f(int n) {
    if (n == 1) return 1;
    return (f(n - 1) + 1) * 2;
}


int main() {
    int n;
    cin >> n;
    printf("%d\n", f(n));
    return 0;
}
