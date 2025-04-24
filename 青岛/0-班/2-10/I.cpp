/*************************************************************************
	> File Name: I.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 06:27:51 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;

#define MAX_N 100000

class A {
public :
    long long p1, p2, ind;
};

int x[MAX_N + 5], y[MAX_N + 5];
A arr[MAX_N + 5];

long long my_pow(long long x) {
    return x * x;
}

bool CMP(A a, A b) {
    return a.p1 < b.p1;
}

int main() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i].p1 = my_pow(x[i] - x1) + my_pow(y[i] - y1);
        arr[i].ind = i;
    }
    sort(arr, arr + n, CMP);
    for (int i = n - 1; i >= 0; i--) {
        long long temp = my_pow(x[arr[i].ind] - x2) + my_pow(y[arr[i].ind] - y2);
        arr[i].p2 = max(temp, arr[i + 1].p2);
    }
    long long ans = arr[0].p2;
    for (int i = 0; i < n; i++) {
        ans = min(ans, arr[i].p1 + arr[i + 1].p2);
    }
    cout << ans << endl;
    return 0;
}
