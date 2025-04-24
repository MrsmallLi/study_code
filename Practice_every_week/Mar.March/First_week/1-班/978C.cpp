/*************************************************************************
	> File Name: 978C.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 10:32:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 200000
#define int long long

int arr[MAX_N + 5] = {0};
int b[MAX_N + 5] = {0};


int32_t main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int sum = 0, i = 0, j = 0;
    while (i < m) {
        while (sum + arr[j] < b[i]) {
            sum += arr[j++];
        }
        cout << j + 1 << " " << b[i] - sum << endl;
        i++;
    }
    return 0;
}
