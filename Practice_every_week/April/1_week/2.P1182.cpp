/*************************************************************************
	> File Name: 2.P1182.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Apr 2025 02:38:31 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000

int arr[MAX_N + 5];
int n, m;
int num;

bool check(int x) {
    int cnt = 0;
    int temp = 0;
    for (int i = 1; i <= n; i++) {
        temp += arr[i];
        if (temp > x) return false;
        if (i + 1 <= n && temp + arr[i + 1] <= x) continue;
        temp = 0;
        cnt += 1;
    }
    return cnt <= m;
}

int find()  {
    int l = 0, r = num, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid; 
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        num += arr[i];
    }
    cout << find() << endl;
    return 0;
}
