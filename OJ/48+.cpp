/*************************************************************************
	> File Name: 48+.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Apr 2025 02:10:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define int long long
#define MAX_V 100000

int w[MAX_V + 5], v[MAX_V + 5];
int f[MAX_V + 5];

int32_t main() {
    int n, V;
    cin >> n >> V;
    for (int i = 1; i <= n; i++)  {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= w[i]; j--) {
            for (int k = 1; k * w[i] <= j; k++) {
                f[j] = max(f[j], f[j - k * w[i]] + k * v[i]);
            }
        }
    }
    cout << f[V] << endl;
    return 0;
}
