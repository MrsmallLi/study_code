/*************************************************************************
	> File Name: 245.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 May 2024 10:42:00 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int mid = arr[n / 2], ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(arr[i] - mid);
    }
    cout << ans << endl;
    return 0;
}
