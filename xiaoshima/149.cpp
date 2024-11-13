/*************************************************************************
	> File Name: 149.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Nov 2024 03:22:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 2000000


bool is_prime(int x) {
    for (int i = 2; i < x; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

int prime[MAX_N + 5];
int prime_num[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime_num[++prime_num[0]] = i;
        for (int j = 1; i * prime_num[j] <= MAX_N; j++) {
            prime[i * prime_num[j]] = 1;
            if (i % prime_num[j] == 0) break;
        }
    }
    return ;
}


int main() {
    int l, r;
    cin >> l >> r;
    init();
    prime[0] = 1;
    prime[1] = 1;
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        //if (!is_prime(i)) continue;
        if (prime[i]) continue;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
