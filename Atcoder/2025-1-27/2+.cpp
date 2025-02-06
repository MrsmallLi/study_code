/*************************************************************************
	> File Name: 2+.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 09:58:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long arr[105] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int flag = 1;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] * arr[i] == arr[i - 1] * arr[i + 1]) continue;
        flag = 0;
        break;
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
