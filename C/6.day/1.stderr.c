/*************************************************************************
	> File Name: 1.stderr.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Mar 2024 03:03:09 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    //利用标准输出流输出
    printf("hello world\n");// stdout
    int n;
    //利用标准输入流进行读取数据
    scanf("%d", &n);// stdin
    printf("n = %d\n", n);
    //利用了标准错误输出流进行输出数据
    perror("out of range\n");//stderr

    return 0;
}
