/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Apr 2025 11:36:28 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX_N 1000000
#define MAX_M 1000000000000
#define int long long

int prime[MAX_N + 5];
vector<int> num;

int max_num = -1;


void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] >= MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    const int max_n = 1e12;
    for (int i = 1; prime[i] <= 1000; i++) {
        for (int j = i + 1; j <= prime[0]; j++) {
            int x = prime[i] * prime[i];
            int y = prime[j] * prime[j];
            for (int k = 1; k <= max_n / y / x; k *= x) {
                for (int g = 1; g <= max_n / k / y; g *= y) {
                    num.push_back(k * g * x * y);
                }
            }
        }
    }
    sort(num.begin(), num.end());
    return ;
}


int find(int n) {
    int l = 0, r = num.size(), mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (num[mid] <= n) l = mid;
        else r = mid - 1;
    }
    return num[l];
}

void solve() {
    int n;
    cin >> n;
    cout << find(n) << endl;
    return ;
}



int32_t main() {
    init();
    //printf("min g = %lld\n", max_num);
    //for (int i = 0; i < 10; i++) cout << num[i] << endl;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
