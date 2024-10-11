/*************************************************************************
	> File Name: 145.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Oct 2024 02:31:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[200005] = {0};

int main() {
    int n, m;
    cin >> n;
    int cnt;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (m != arr[i]) continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}

