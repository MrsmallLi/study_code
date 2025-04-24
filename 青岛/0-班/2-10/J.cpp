/*************************************************************************
	> File Name: J.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 08:08:34 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 400000

class A {
public :
    int x, y, w, ind, flag;
};

A arr[MAX_N + 5];

bool CMP1(A a, A b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool CMP2(A a, A b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

int ans[MAX_N + 5];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
        arr[i].w = 0;
        arr[i].ind = i;
        arr[i].flag = 0;
    }
    for (int i = n; i < n + m; i++) {
        cin >> arr[i].x >> arr[i].y;
        arr[i].w = 1;
        arr[i].ind = i;
        arr[i].flag = 0;
    }
    sort(arr, arr + n + m, CMP1);
    for (int i = 1; i < n + m; i++) {
        if (arr[i].w == arr[i - 1].w) continue;
        if (arr[i].x != arr[i - 1].x) continue;
        arr[i].flag = 1;
        arr[i - 1].flag = 1;
    }
    sort(arr, arr + n + m, CMP2);
    for (int i = 1; i < n + m; i++) {
        if (arr[i].w == arr[i - 1].w) continue;
        if (arr[i].y != arr[i - 1].y) continue;
        arr[i].flag = 1;
        arr[i - 1].flag = 1;
    }
    for (int i = 0; i < n + m; i++) ans[arr[i].ind] = arr[i].flag;
    ans[arr[0].ind] = arr[0].flag;
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << endl;
    for (int i = n; i < n + m; i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
