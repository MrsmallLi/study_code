/*************************************************************************
	> File Name: 7.mult_array.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Mar 2024 06:25:34 PM CST
 ************************************************************************/

#include<stdio.h>


int main() {
    int b[3][4];
    int cnt = 1;
    for (int i = 0; i < 3; i++) {//对行进行循环
        for (int j = 0; j < 4; j++) {//对列进行循环
            b[i][j] = cnt++;
        }
    }
    for (int i = 0; i < 3; i++) {//对行进行循环
        for (int j = 0; j < 4; j++) {//对列进行循环
            j && printf(" ");
            printf("%3d", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
