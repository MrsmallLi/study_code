/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 08:08:12 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (n == i * j) continue;
            sum += i * j;
        }
    }
    cout << sum << endl;
    return 0;
}
