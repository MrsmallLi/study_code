/*************************************************************************
	> File Name: 237.c
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 04:57:22 PM CST
 ************************************************************************/

#include<stdio.h>

int n;
int arr[15];
int flag[10] = {0};


void output() {
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    putchar(10);
    return ;
}

void f(int ind) {
    if (ind == n) {
        output();
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (flag[i]) continue;
        arr[ind] = i;
        flag[i] = 1;
        f(ind + 1);
        flag[i] = 0;
    }
    return ;
}


int main() {
    scanf("%d", &n);
    f(0);
    return 0;
}
