/*************************************************************************
	> File Name: 230B.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2025 06:48:15 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX_N 100000
#define MAX_M 1000000

long long arr[MAX_N + 5];
unordered_map<long long, bool> mp;
long long prime[MAX_M + 5];

void init() {
    //线性筛,将小于10^6的素数找出来
    for (int i = 2; i <= MAX_M; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_M) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    //标记T数字
    for (int i = 1; i <= prime[0]; i++) {
        mp[prime[i] * prime[i]] = true;
    }
}

int main() {
    int n;
    cin >> n;
    init();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (mp[arr[i]]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
