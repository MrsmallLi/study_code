/*************************************************************************
	> File Name: 5.2028H.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Apr 2025 04:47:07 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map> 
using namespace std;

#define MAX_N 100000

int n, q, x, mid_num;
int arr[MAX_N + 5];

bool check(int mid) {
    //if (arr[mid] >= mid_num) return true;
    int cnt = arr[mid];
    for (int i = 1; i * x <= n; i++) {
        cnt += arr[min(i * x + mid, n)];
        cnt -= arr[i * x - 1];
        if (cnt >= mid_num) return true;
    }
    //printf("arr[mid] = %d, mid = %d, cnt = %d\n", arr[mid], mid, cnt);
    return cnt >= mid_num;
}

int find() {
    int l = 0, r = x, mid;
    while (l < r) {
        mid = (l + r) / 2;
        //printf("mid = %d, check(mid) = %d\n", mid, check(mid));
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}


void solve() {
    cin >> n >> q;
    memset(arr, 0, sizeof(int) * (n + 1));
    if (n & 1) {
        mid_num = (n + 1) / 2;
    } else {
        mid_num = (n + 2) / 2;
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[a] += 1;
    }
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
    }
    /*
    for (int i = 1; i <= n; i++) {
        printf("i = %d, arr[i] = %d\n", i, arr[i]);
    }
    */
    unordered_map<int, int> mp;
    for (int i = 0; i < q; i++) {
        cin >> x;
        i && cout << " ";
        if (mp.find(x) != mp.end()) {
            cout << mp[x];
        } else {
            mp[x] = find();
            cout << mp[x];
        }
    }
    cout << endl;
    return ;
}


int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
