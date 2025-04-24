/*************************************************************************
	> File Name: 197.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 12:34:12 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000

typedef struct student {
    int h, ind;
} student;

student arr[MAX_N + 5];

bool CMP(student &a, student &b) {
    if (a.h == b.h) return a.ind < b.ind;
    return a.h < b.h;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].h;
        arr[i].ind = i;
    }
    sort(arr + 1, arr + n + 1, CMP);
    for (int i = 1; i <= n; i++) {
        i != 1 && printf(" ");
        cout << arr[i].ind;
    }
    cout << endl;
    return 0;
}
