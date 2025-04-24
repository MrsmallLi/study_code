/*************************************************************************
	> File Name: E.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 02:47:45 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 200000

int a[MAX_N + 5];
int b[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)  {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)  {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n - 1);
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > b[i]) {
            cout << -1 << endl;
            flag = 1;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (flag) break;
        if (a[i + 1] > b[i]) {
            cout << a[i + 1] << endl;
            flag = 1;
            break;
        }
    }
    if (!flag) cout << a[0] << endl;
    return 0;
}
