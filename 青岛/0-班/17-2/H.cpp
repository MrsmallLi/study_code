/*************************************************************************
	> File Name: I.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Feb 2025 09:23:18 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000




int arr[MAX_N + 5] = {0};

void check(int l, int r) {
    arr[l] ^= 1;
    arr[r + 1] ^= 1;
    return ;
}

int find(int ind) {
    int ans = arr[0];
    for (int i = 1; i <= ind; i++) {
        ans ^= arr[i];
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a;
        cin >> a;
        switch (a) {
            case 1: {
                int l, r;
                cin >> l >> r;
                check(l, r);
            } break;
            case 2: {
                int ind;
                cin >> ind;
                cout << find(ind) << endl;;
            } break;
        }
    }
    return 0;
}
