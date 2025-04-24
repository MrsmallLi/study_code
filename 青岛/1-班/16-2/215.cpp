/*************************************************************************
	> File Name: 215.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 11:19:00 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

#define MAX_N 40

typedef struct student {
    string name;
    int sum;//成绩总和
} st;

st arr[MAX_N + 5];

bool CMP(st a, st b) {
    return a.sum > b.sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> arr[i].name >> a >> b >> c >> d;
        arr[i].sum = a + b + c + d;
    }
    sort(arr, arr + n, CMP);
    for (int i = 0; i < 3; i++) {
        cout << arr[i].name << endl;
    }
    return 0;
}
