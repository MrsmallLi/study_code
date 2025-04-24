/*************************************************************************
	> File Name: P3390.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 09:24:46 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

typedef long long ll;

ll n, k;
ll mod = 1e9 + 7;
long long arr[105][105];
long long temp[105][105];

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) continue;
            temp[i][j] = 1;
        }
    }
    return ;
}

void mul(long long (*a)[105], long long (*b)[105]) {
    long long c[105][105] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int s = 1; s <= n; s++) {
                c[i][j] += a[i][s] * b[s][j];
                c[i][j] %= mod;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = c[i][j];
        }
    }
}

void quick_pow(ll q) {
    init();
    while (q) {
        if (q & 1) mul(temp, arr);
        mul(arr, arr);
        q >>= 1; 
    }
    return ; 
}


int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    quick_pow(k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j != 1) cout << " ";
            cout << temp[i][j];
        }
        cout << endl;
    }

    return 0;
}
