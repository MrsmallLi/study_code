/*************************************************************************
	> File Name: B.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Feb 2025 09:26:41 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 200000

class A {
public :
    int l, r;
};

bool CMP(A a, A b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        A arr[MAX_N + 5] = {0};
        for (int i = 0; i < n; i++) {
            cin >> arr[i].l >> arr[i].r;
        }
        sort(arr, arr + n, CMP);
        
    } 

    return 0;
}
