/*************************************************************************
	> File Name: 237.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Jan 2025 04:50:18 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, cnt = 0;
int arr[20];
int val[20];

void output() {
    for (int i = 0; i < n; i++) {
        i && cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}


void fun() {
    if (n == cnt) {
        output();
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (val[i]) continue;
        val[i] = 1;
        arr[cnt++] = i;
        fun();
        val[i] = 0;
        cnt--;
    }
}

int main() {
    cin >> n;
    fun();
    return 0;
}
