/*************************************************************************
	> File Name: 186.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Oct 2024 02:51:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100000 

int arr[MAX_N + 5] = {0};


int func(int i, int n) {
    if (i >= n) return 0;
    return func(i + arr[i], n) + 1;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    cout << func(0, n) << endl;

    return 0;
}
