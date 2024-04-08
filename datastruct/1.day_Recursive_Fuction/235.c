/*************************************************************************
	> File Name: 235.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Apr 2024 04:40:04 PM CST
 ************************************************************************/

#include <stdio.h>

int n;
int arr[15];
int ind;

void f(int i) {
    if (i > n) return ;
    for (int k = i; k <= n; k++) {
        arr[ind++] = k;
        for (int j = 0; j < ind; j++) {
            j && printf(" ");
            printf("%d", arr[j]);
        }
        printf("\n");
        f(k + 1);
        ind--;
    }
    return ;
}


int main() {
    scanf("%d", &n);
    f(1);
    return 0;
}
