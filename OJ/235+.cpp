/*************************************************************************
	> File Name: 235+.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Jan 2025 04:36:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n;
int arr[20] = {0};
int ind = 0;

void output() {
    for (int i = 0; i < ind; i++) {
        i && cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}

void fun(int x) {
    if (x > n) return ;
    for (int i = x; i <= n; i++) {
        arr[ind++] = i;
        output();
        fun(i + 1);
        ind--;
    }
    return ;
}


int main() {
    cin >> n;
    fun(1);

    return 0;
}
