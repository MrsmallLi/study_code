/*************************************************************************
	> File Name: 230.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Oct 2024 04:39:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 30
int f[MAX_N + 5];


int main() {
    int n;
    cin >> n;
    f[1] = 1;
    f[0] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1]  + f[i - 2];
    }
    cout << f[n] << endl;
    return 0;
}
