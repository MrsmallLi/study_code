/*************************************************************************
	> File Name: 236.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Oct 2024 03:17:37 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[15];

void output(int m) {
    for (int i = 0; i < m; i++) {
        i && cout << " ";
        cout << num[i];
    }
    cout << endl;
}


void func(int i, int j, int n, int m) {
    if (j > n) return ;
    for (int k = j; k <= n; k++) {
        num[i] = k;
        if (i == m - 1) output(m);
        func(i + 1, k + 1, n, m);
    }
    return ;
}


int main() {
    int n, m;
    cin >> n >> m;
    func(0, 1, n, m);

}
