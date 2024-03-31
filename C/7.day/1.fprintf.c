/*************************************************************************
	> File Name: 1.fprintf.c
	> Author: 
	> Mail: 
	> Created Time: Sun 31 Mar 2024 10:13:11 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("./data.txt", "w");
    //当没有成功打开文件时，打印提示信息，并结束程序
    if (fp == NULL) {
        printf("failed to open file\n");
        exit(1);
    }
    //向文件中打印内容
    fprintf(fp, "hello world\n");
    int a = 123, b = 456;
    fprintf(fp, "a = %d, b = %d\n", a, b);
    fclose(fp);
    return 0;
}
