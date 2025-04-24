/*************************************************************************
	> File Name: F.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 10 Feb 2025 03:16:58 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000
#define int long long

class T {
public :
    int s, a, e, all;
};

T arr[MAX_N + 5];

bool CMP(const T &a, const T &b) {
    return a.all < b.all;
}

int32_t main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].s >> arr[i].a >> arr[i].e;
        arr[i].all = arr[i].s + arr[i].a + arr[i].e;
    }
    sort(arr, arr + n, CMP);
    int speed = arr[0].a + arr[0].s;
    int ans = speed;
    for (int i = 1; i < n; i++) {
        speed = speed + arr[i].a + arr[i].s + arr[i - 1].e;
        ans += speed;
    }
    cout << ans << endl;
    return 0;
}
