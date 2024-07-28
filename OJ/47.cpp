/*************************************************************************
	> File Name: 47.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Jun 2024 12:45:44 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 100
#define MAX_V 1000000
int arr_v[MAX_N + 5] = {0};
int arr_w[MAX_N + 5] = {0};
int f[MAX_V + 5] = {0};

int main() {
    int v, n;
    cin >> v >> n;
    for (int i = 1; i <= n; i++) scanf("%d%d", (arr_v + i), arr_w + i);
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= arr_v[i]; j--) {
            f[j] = max(f[j], f[j - arr_v[i]] + arr_w[i]);
        }
    }
    cout << f[v] << endl;
    return 0;
}
