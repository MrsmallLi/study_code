/*************************************************************************
	> File Name: 236.c
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 04:50:42 PM CST
 ************************************************************************/

#include<stdio.h>

int n, m;
int arr[15];
int ind = 0;

void f(int i) {
    if (i > m) return ;
    for (int k = i; k <= m; k++) {
        arr[ind++] = k;
        if (ind == n) {
            for (int j = 0; j < ind; j++) {
                j && printf(" ");
                printf("%d", arr[j]);
            }
            printf("\n");
        }
        f(k + 1);
        ind--;
    }
    return ;
}

int main() {
    scanf("%d%d", &m, &n);
    f(1);
    return 0;
}
