/*************************************************************************
	> File Name: 145+.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Oct 2024 03:26:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[20005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= m; i++) {
        int num = i;
        while (num <= n) {
            arr[num] ^= 1;
            num += i;
        }
    }
    for (int i = 1, flag = 0; i <= n; i++) {
        if (arr[i]) continue;
        flag && cout << ",";
        cout << i;
        flag = 1;
    }
    cout << endl;
    return 0;
}
