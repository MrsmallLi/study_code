/*************************************************************************
	> File Name: 139.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Oct 2024 03:11:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[1000005];


int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    for (int i = n - 1; i >= x - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[x - 1] = arr[n];
    for (int i = 0; i < n; i++) {
        i && cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
