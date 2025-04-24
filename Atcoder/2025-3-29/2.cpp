/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Mar 2025 08:06:11 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;


#define MAX_N 200000
class A {
public :
    int x, ind, pre;
};

bool CMP(A a, A b) {
    return a.x > b.x;
}
A arr[MAX_N + 5];

bool CMP2(A a, A b) {
    return a.ind < b.ind;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x ;
        arr[i].ind = i;
    }
    sort(arr, arr + n, CMP);
    //cout << endl;
    int r = 1, pre = 1, max_num = arr[0].x;
    for (int i = 0; i < n; i++) {
        if (arr[i].x == max_num) {
            arr[i].pre = pre; 
            r += 1;
        } else {
            arr[i].pre = r;
            pre = r;
            max_num = arr[i].x;
            r++;
        }
    }
    sort(arr, arr + n, CMP2);
    for (int i = 0; i < n; i++) {
        cout << arr[i].pre << endl;
    }
    return 0;
}
