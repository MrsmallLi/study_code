/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Feb 2025 09:17:37 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[15];

void output(int temp) {
    for (int i = 0; i <= temp; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    return ;
}

void func(int temp, int num, int n) {
    if (temp >= n || num > n) return ;
    for (int i = num; i <= n; i++) {
        arr[temp] = i;
        output(temp);
        func(temp + 1, i + 1, n);
    }
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    func(0, 1, n);
    return 0;
}
