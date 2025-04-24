/*************************************************************************
	> File Name: 4.474B.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Mar 2025 05:44:37 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000

int arr[MAX_N + 5];
int n, m;

int find(int x) {
    int l = 1, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (arr[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

void solve() {
    int num;
    cin >> num;
    cout << find(num) << endl;
    return ;
}



int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    cin >> m;
    while (m--) solve();


    return 0;
}
