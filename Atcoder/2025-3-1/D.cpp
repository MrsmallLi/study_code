/*************************************************************************
	> File Name: D.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Mar 2025 08:38:38 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

#define MAX_N 1000000



//
int arr[MAX_N + 5];

//
int ind[MAX_N + 5];

//
int val[MAX_N + 5];


void solve() {
    int q;
    cin >> q;
    switch (q) {
        case 1: {
            int a, b;
            scanf("%d%d", &a, &b);
            arr[a] = ind[b];
        } break;
        case 2: {
            int a, b;
            scanf("%d%d", &a, &b);
            swap(ind[a], ind[b]);
            swap(val[ind[a]], val[ind[b]]);
        } break;
        case 3: {
            int a;
            cin >> a;
            cout << val[arr[a]] << endl;
        } break;
    }
    return ;
}

void init(int n) {
    for (int i = 1; i <= n; i++) arr[i] = i, ind[i] = i, val[i] = i;
}


int main() {
    int n, q;
    cin >> n >> q;
    init(n);
    while (q--) solve();
    return 0;
}
