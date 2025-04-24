/*************************************************************************
	> File Name: 47++.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Apr 2025 02:03:55 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100
#define MAX_M 10000

int v[MAX_N + 5], w[MAX_N + 5];
int f[MAX_M + 5];

int main() {
    int n, V;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[V] << endl;
    return 0;
}
