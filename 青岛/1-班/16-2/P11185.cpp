/*************************************************************************
	> File Name: P11185.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 07:02:51 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 200000

typedef struct student {
    int num, ind;
} st;

st arr1[MAX_N + 5];
st arr2[MAX_N + 5];
st arr3[MAX_N + 5];

int ans[MAX_N + 5];

bool CMP(st a, st b) {
    return a.num > b.num;
}

void func(st *arr, int n) {
    int pre = 1;
    for (int i = 1; i <= n; i++) {
        if (arr[i].num == arr[i - 1].num) {
            ans[arr[i].ind] = min(ans[arr[i].ind], pre);
        } else {
            ans[arr[i].ind] = min(ans[arr[i].ind], i);
            pre = i;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr1[i].num >> arr2[i].num >> arr3[i].num;
        arr1[i].ind = i;
        arr2[i].ind = i;
        arr3[i].ind = i;
        ans[i] = INT_MAX;
    }
    sort(arr1 + 1, arr1 + n + 1, CMP);
    sort(arr2 + 1, arr2 + n + 1, CMP);
    sort(arr3 + 1, arr3 + n + 1, CMP);
    func(arr1, n);
    func(arr2, n);
    func(arr3, n);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}rr2[i].num >> arr3[i].num;
        arr1[i].ind = i;
        arr2[i].ind = i;
        arr3[i].ind = i;
        ans[i] = INT_MAX;
    }
    sort(arr1 + 1, arr1 + n + 1, CMP);
    sort(arr2 + 1, arr2 + n + 1, CMP);
    sort(arr3 + 1, arr3 + n + 1, CMP);
    func(arr1, n);
    func(arr2, n);
    func(arr3, n);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
