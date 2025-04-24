/*************************************************************************
	> File Name: 219.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 11:38:22 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10000

//int arr[MAX_N + 5];
vector<int> arr(MAX_N + 5);

bool CMP(int a, int b) { return a > b; }

int main() {
    int n, l1, r1, l2, r2;
    cin >> n >> l1 >> r1 >> l2 >> r2;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin() + l1, arr.begin() + r1 + 1);
    sort(arr.begin() + l2, arr.begin() + r2 + 1, CMP);
    for (int i = 1; i <= n; i++) {
        i != 1 && cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
