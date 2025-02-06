/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 11 Jan 2025 08:27:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long num[1000005] = {0};
long long arr[1000005] = {0};

int binserch_find(int x, int n) {
    int l = -1 , r = n - 1, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (mid < 0) break;
        if (num[mid] <= x) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        int ind = binserch_find(num[i] / 2, n);
        if (ind < 0) continue;
        cnt += ind + 1;
    }
    cout << cnt << endl;
    return 0;
}
