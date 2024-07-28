/*************************************************************************
	> File Name: 48.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Jun 2024 01:03:42 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 10000

int f[MAX_N + 5] = {0};

int main() {
    int n, V;
    cin >> n >> V;
    for (int i = 1, v, w; i <= n; i++) {
        scanf("%d%d", &v, &w);
        for (int j = v; j <= V; j++) {
            f[j] = max(f[j], f[j - v] + w);
        }
    }
    cout << f[V] << endl;
    return 0;
}
