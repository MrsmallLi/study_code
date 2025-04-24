/*************************************************************************
	> File Name: 213.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 11:07:07 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 30

int arr[MAX_N + 5];
int b[10];

bool CMP(int a, int b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, CMP);
    for (int i = 0; i < n; i++) {
        if (arr[i] == 100) {
            b[1] += 1;
        } else if (arr[i] >= 90) {
            b[2] += 1;
        } else if (arr[i] >= 80) {
            b[3] += 1;
        } else if (arr[i] >= 70) {
            b[4] += 1;
        } else if (arr[i] >= 60) {
            b[5] += 1;
        } else {
            b[6] += 1;
        }
        cout << arr[i] << endl;
    }
    for (int i = 1; i <= 6; i++) {
        i != 1 && printf(" ");
        cout << b[i];
    }
    cout << endl;
    return 0;
}
