/*************************************************************************
	> File Name: 186.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 04:28:55 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
int n;

int f(int i, int *arr) {
    if (i >= n) return 0;
    return f(i + arr[i], arr) + 1;
}


int main() {
    cin >> n;
    int arr[n + 5];
    memset(arr, 0, n + 5);
    for (int i = 0; i < n; i++) cin >> arr[i];
    printf("%d\n", f(0, arr));
    return 0;
}
