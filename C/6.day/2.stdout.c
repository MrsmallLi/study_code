/*************************************************************************
	> File Name: 2.stdout.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Mar 2024 03:08:11 PM CST
 ************************************************************************/

#include<stdio.h>



int main() {
    printf("alskaskldjaslkdjlaskld123\n");
    //stdout在操作系统种也是文件
    //利用fflush函数进行对stdout文件进行冲刷，也就是刷新他的缓冲区
    //然后内容就会打印到终端上
    fflush(stdout);
    *((int *)(0)) = 5;
    return 0;
}
