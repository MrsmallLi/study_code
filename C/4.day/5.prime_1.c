/*************************************************************************
	> File Name: 5.prime.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Mar 2024 05:00:19 PM CST
 ************************************************************************/

#include<stdio.h>

int prime[100] = {0};

void init_prime(int n) {
    prime[0] = prime[1] = 1;
    //优化1
    //证明:假如 n = a * b,a和b中一定有一个是小于等于根号下n的
    //那么n也被小于等于根号n的素数给标记了
    //举个例子100，根号下100就是10
    //那么10下面的2，就已经把100标记了
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) continue;
        //优化2
        //证明: j = a * i, 当a < i时，j 已经被a这个素数标记了
        //那么这里用a的话，就重复标记了
        //例子a = 2
        //j = 2 * i
        //当i = 2标记了6，循环是 j += i,标记顺序是4，6，8
        //当i = 3时又标记了6,循环是 j += i,标记顺序是6, 9，12
        for (int j = i * i; j <= n; j += i) {
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
