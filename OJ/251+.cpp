/*************************************************************************
	> File Name: 251+.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 09:44:02 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int y[MAX_N + 5];
int x[MAX_N + 5];


int main() {
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(y, y + n);
    sort(x, x + n);
    for (int i = 0; i < n; i++) x[i] -= i;
    sort(x, x + n);
    int x1 = x[n / 2];
    int y1 = y[n / 2];
    for (int i = 0; i < n; i++) {
        ans += abs(y[i] - y1) + abs(x[i] - x1);
    }
    cout << ans << endl;
    return 0;
}
