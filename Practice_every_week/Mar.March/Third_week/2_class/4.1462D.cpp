/*************************************************************************
	> File Name: 4.1462D.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Mar 2025 07:09:45 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 3000

int arr[MAX_N + 5];

int find(int sum, int n) {
    int cnt = 0;
    int flag = 1;
    int l = 0, r = 0;
    while (r < n) {
        int num = arr[l];
        while (r < n && num < sum) num += arr[++r], cnt += 1;
        if (num != sum) {
            return -1;
        } 
        r = r + 1;
        l = r;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int ans = 0;
    for (int k = 0; k < n; k++)  {
        if ((sum % (n - k))) continue;
        int num = sum / (n - k);
        //printf("%lld\n", num);
        int flag = find(num, n);
        if (flag == -1) continue;
        ans = k;
        break;
    }
    cout << ans << endl;
    return ;
}


int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
