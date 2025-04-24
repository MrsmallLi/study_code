/*************************************************************************
	> File Name: 158A.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 03:14:01 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100

int arr[MAX_N + 5];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0 || arr[i] < arr[k]) break;
        cnt += 1;
    }
    cout << cnt << endl;
    return 0;
}
