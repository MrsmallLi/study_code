/*************************************************************************
	> File Name: 219.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 01:23:17 AM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 10000

vector<int> arr(MAX_N + 5);

bool CMP(int a, int b) {
    return a > b;
}

int main() {
    int n, l1, r1, l2, r2;
    cin >> n >> l1 >> r1 >> l2 >> r2;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin() + l1 - 1, arr.begin() + r1);
    sort(arr.begin() + l2 - 1, arr.begin() + r2, CMP);
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
