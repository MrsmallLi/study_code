/*************************************************************************
	> File Name: 236+.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Jan 2025 04:41:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int n, m;

int arr[20] = {0};
int cnt = 0;

void output() {
    for (int i = 0; i < cnt; i++) {
        i && cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}

void fun(int x) {
    if (cnt == m) {
        output();
        return ;
    }
    if (x > n) return ;
    for (int i = x; i <= n; i++) {
        arr[cnt++] = i;
        fun(i + 1);
        cnt--;
    }
    return ;
}


int main() {
    cin >> n >> m;
    fun(1);
    return 0;
}
