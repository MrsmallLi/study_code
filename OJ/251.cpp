/*************************************************************************
	> File Name: 251.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Apr 2024 01:32:59 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10000
int x[MAX_N + 5], y[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int arr[MAX_N + 5];
    sort(x, x + n);
    for (int i = 0; i < n; i++) {
        arr[i] = x[i] - i;
    }
    nth_element(y, y + n / 2, y + n);
    nth_element(arr, arr + n / 2, arr + n);
    int X = arr[n / 2];
    int Y = y[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(y[i] - Y);
        ans += abs(arr[i] - X);
    }
    cout << ans << endl;
    return 0;
}
