/*************************************************************************
	> File Name: test4.c
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Mar 2024 05:33:02 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    switch (a) {
        //break的作用，如果a = 1，那么就会进入case 1, 执行case 1中的代码段
        //如果没有break，那么执行完case 1中的语句，会接着执行case 2中的语句
        //直到switch 结构末尾才结束
        //那么break的作用就是在相应位置结束switch语句，不在往下执行
        case 1: printf("case a = 1\n"); break;
        case 2: printf("case a = 2\n"); break;
        case 3: printf("case a = 3\n"); break;
        case 4: printf("case a = 4\n"); break;
        default : printf("default value\n"); break;
    }

    return 0;
}
