/*************************************************************************
	> File Name: B.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Mar 2025 08:03:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 50

char arr[MAX_N + 5][MAX_N + 5];

void color(int i, int j, int flag) {
    int temp = i;
    for (; i <= j; i++) {
        for (int k = temp; k <= j; k++) {
            arr[i][k] = (flag ? '#' : '.');
        }
    }
    return ;
}


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int j = n + 1 - i;
        color(i, j, (i & 1));
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", arr[i][j]);
        }
        cout << endl;
    }


    return 0;
}
