/*************************************************************************
	> File Name: 14.1486C1.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Mar 2025 04:13:09 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int func(int l, int r) {
    int x;
    cout << "? " << l << " " << r << endl;
    fflush(stdout);
    cin >> x; 
    return x;
}

int find(int l, int r) {
    while (l < r) {
        int x = func(l, r);
        int mid = (l + r) / 2;
        if (r - l == 1) {
            if (l == x) return r;
            else return l;
        }
        if (x <= mid) {
            int l_num = func(l, mid);
            if (l_num != x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        } else {
            if (r == mid + 1) {
                mid --;
            }
            int r_num = func(mid + 1, r);
            if (r_num != x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
    }
    return l;
}



int main() {
    int n;
    cin >> n;
    int ans = find(1, n);
    cout << "! " << ans << endl;
    return 0;
}
