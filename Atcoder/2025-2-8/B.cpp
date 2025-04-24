/*************************************************************************
	> File Name: B.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Feb 2025 08:03:58 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int arr[1005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0, a; i < m; i++) {
        cin >> a;
        arr[a] = 1;
    }
    cout << n - m << endl;
    for (int i = 1, flag = 1; i <= n; i++) {
        if (arr[i]) continue;
        if (!flag) {
            cout << " ";
        }
        cout << i;
        flag = 0;
    }
    cout << endl;
    return 0;
}
