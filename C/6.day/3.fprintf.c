/*************************************************************************
	> File Name: 3.fprintf.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Mar 2024 03:26:29 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    //向标准输出流种输出hello world
    fprintf(stdout, "hello world\n");
    //向标准输入流种读入数据
    int n;
    fscanf(stdin, "%d", &n);
    //向标准错误输出流种打印n的值
    fprintf(stderr, "n = %d\n", n);
    return 0;
}
