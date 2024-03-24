/*************************************************************************
	> File Name: 5.prime.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Mar 2024 05:00:19 PM CST
 ************************************************************************/

#include<stdio.h>

int prime[100] = {0};

void init_prime(int n) {
    //初始化0和1不是素数
    prime[0] = prime[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) continue;//如果被标记了，说明不是素数，就不用再去标记
        for (int j = 2 * i; j <= n; j += i) {
            prime[j] = 1;//标记当前数为合数
        }
    }
    return ;
}


int main() {
    //求1-n的素数
    int n;
    printf("input n(0 < n && n <= 100) :");
    scanf("%d", &n);
    init_prime(n);
    for (int i = 0; i <= n; i++) {
        if (prime[i]) continue;//被标记说明i是合数不打印
        printf("%d\n", i);
    }
    return 0;
}
