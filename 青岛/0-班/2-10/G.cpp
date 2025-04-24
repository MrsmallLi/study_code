/*************************************************************************
	> File Name: G.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 03:47:55 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

#define MAX_N 1000

class Data {
public :
    double l, r;
};

Data arr[MAX_N + 5];

bool CMP(const Data &a, const Data &b) {
    if (a.r != b.r) return a.r < b.r;
    return a.l > b.l;
}


int main() {
    int n;
    double x, y, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (y > r) {
            cout << -1 << endl;
            return 0;
        }
        double c = sqrt(r * r - y * y);
        arr[i].l = x - c;
        arr[i].r = x + c;
    }
    sort(arr, arr + n, CMP);
    double pre = arr[0].r;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (pre >= arr[i].l) continue;
        pre = arr[i].r;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}

