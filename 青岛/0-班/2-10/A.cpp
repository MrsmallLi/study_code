/*************************************************************************
	> File Name: A.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 10:35:40 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10000
#define int long long

typedef class student {
public :
    int c, m, num, all, cm, max;
    int ind;
} st;

st arr[MAX_N + 5];

bool CMP(const st &a, const st &b) {
    if (a.all != b.all) {
        return a.all > b.all;
    } else if (a.cm != b.cm){
        return a.cm > b.cm; 
    } else {
        return a.max > b.max;
    }
}

int ans[MAX_N + 5];

int32_t main() {
    int n;
    cin >> n;
    for (int i = 1, e; i <= n; i++) {
        cin >> arr[i].c >> arr[i].m >> e;
        arr[i].all = arr[i].c + arr[i].m + e;
        arr[i].cm  = arr[i].m + arr[i].c;
        arr[i].max = max(arr[i].c, arr[i].m);
        arr[i].num = i;
    }
    sort(arr + 1, arr + n + 1, CMP);
    for (int i = 1; i <= n; i++) {
        //printf("all = %d, cm =%d, max = %d\n", arr[i].all, arr[i].cm, arr[i].max);
        arr[i].ind = i;
        if (arr[i].all == arr[i - 1].all && arr[i].cm == arr[i - 1].cm && arr[i].max == arr[i - 1].max) {
            arr[i].ind = arr[i - 1].ind;
        }
        ans[arr[i].num] = arr[i].ind;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
