/*************************************************************************
	> File Name: 550C.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 08:56:31 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define MAX_N 200000
#define int long long

typedef struct move {
    int f, s, ind;
} m;

map<long long, int> mp;
m arr[MAX_N + 5];

bool CMP(m a, m b) {
    if (a.f != b.f) return a.f > b.f;
    if (a.s != b.s) return a.s > b.s;
    return a.ind < b.ind;
}

int32_t main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a] += 1;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        arr[i].f = mp[b];
        arr[i].ind = i + 1;
    }
    for (int j = 0; j < m; j++) {
        int s;
        cin >> s;
        arr[j].s = mp[s];
    }
    sort(arr, arr + m, CMP);
    cout << arr[0].ind << endl;

    return 0;
}
