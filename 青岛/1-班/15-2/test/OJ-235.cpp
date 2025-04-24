/*************************************************************************
	> File Name: OJ-235.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 10:42:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


#define MAX_N 10

int arr[MAX_N + 5];

void output(int ind) {
    for (int i = 0; i <= ind; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    return ;
}

void fun(int num, int ind, int n) {
    if (num > n || ind >= n) {
        return ;
    }
    for (int i = num; i <= n; i++) {
        arr[ind] = i;
        output(ind);
        fun(i + 1, ind + 1, n);
    }
    return ;
}


int main() {
    int n;
    scanf("%d", &n);
    fun(1, 0, n);
    return 0;
}
