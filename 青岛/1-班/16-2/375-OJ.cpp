/*************************************************************************
	> File Name: 375-OJ.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 07:42:10 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

#define MAX_N 300

typedef struct student {
    int ind, sum, c;
} st;

st arr[MAX_N + 5];

bool CMP(st a, st b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    if (a.c != b.c) return a.c > b.c;
    return a.ind < b.ind;
}


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, m, e;
        cin >> c >> m >> e;
        arr[i].ind = i;
        arr[i].sum = c + m + e;
        arr[i].c = c;
    }
    sort(arr + 1, arr + n + 1, CMP);
    for (int i = 1; i <= 5; i++) {
        cout << arr[i].ind << " " << arr[i].sum << endl;
    }
    return 0;
}
